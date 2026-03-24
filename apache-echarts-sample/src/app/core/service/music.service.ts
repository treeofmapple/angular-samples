import { HttpClient } from '@angular/common/http';
import { MusicData } from '../model/chart.models';
import { Observable } from 'rxjs/internal/Observable';
import { Injectable } from '@angular/core';
import { environment } from '../../../environment/environment.prod';

@Injectable({
  providedIn: 'root',
})
export class MusicService {
  private readonly apiUrl = `${environment.apiUrl}`;

  constructor(private http: HttpClient) {}

  getCustomData(): Observable<MusicData> {
    return this.http.get<MusicData>(this.apiUrl);
  }
}
