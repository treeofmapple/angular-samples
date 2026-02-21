export interface VehicleRequest {
  brand: string;
  model: string;
  color: string;
  plate: string;
}

export interface VehicleResponse {
  id: number;
  brand: string;
  model: string;
  color: string;
  plate: string;
}

export interface PageVehicleResponse {
  content: VehicleResponse[];
  page: number;
  size: number;
  totalPages: number;
}
