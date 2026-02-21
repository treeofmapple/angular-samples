import { Component, EventEmitter, Output } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { VehicleService } from '../../services/vehicle';
import { VehicleResponse } from '../../services/vehicle.model';

@Component({
  selector: 'app-search',
  imports: [FormsModule],
  templateUrl: './search.html',
  styleUrl: './search.scss',
})
export class Search {
  query: string = '';

  constructor(private vehicleService: VehicleService) {}

  @Output() searchChange = new EventEmitter<VehicleResponse | null>();

  onSearch() {
    if (!this.query.trim()) {
      this.searchChange.emit(null);
      return;
    }

    this.vehicleService.findVehicleByPlate(this.query).subscribe({
      next: (vehicle) => {
        this.searchChange.emit(vehicle);
      },
      error: () => {
        this.searchChange.emit(null);
      },
    });
  }
}
