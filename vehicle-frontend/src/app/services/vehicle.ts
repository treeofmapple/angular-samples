import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { PageVehicleResponse, VehicleRequest, VehicleResponse } from './vehicle.model';
import { environment } from '../../environments/environment';

@Injectable({
  providedIn: 'root',
})
export class VehicleService {
  private readonly apiUrl = `${environment.apiUrl}/vehicle`;

  constructor(private http: HttpClient) {}

  findByPages(page: number = 0): Observable<PageVehicleResponse> {
    return this.http.get<PageVehicleResponse>(`${this.apiUrl}?page=${page}`);
  }

  findVehicleById(id: number): Observable<VehicleResponse> {
    return this.http.get<VehicleResponse>(`${this.apiUrl}/${id}`);
  }

  findVehicleByPlate(plate: string): Observable<VehicleResponse> {
    return this.http.get<VehicleResponse>(`${this.apiUrl}?plate=${plate}`);
  }

  createVehicle(request: VehicleRequest): Observable<VehicleResponse> {
    return this.http.post<VehicleResponse>(this.apiUrl, request);
  }

  updateVehicle(id: number, request: VehicleRequest): Observable<VehicleResponse> {
    return this.http.put<VehicleResponse>(`${this.apiUrl}/${id}`, request);
  }

  deleteVehicle(plate: string): Observable<void> {
    return this.http.delete<void>(`${this.apiUrl}/${plate}`);
  }
}
