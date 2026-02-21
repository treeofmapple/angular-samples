import { Routes } from '@angular/router';
import { redirectNearMatch } from './config/tools/redirect-match';

export const routes: Routes = [
  {
    path: '',
    pathMatch: 'full',
    redirectTo: 'products/all',
  },
  {
    path: 'products/:category',
    loadComponent: () => import('./pages/products-grid/products-grid')
  },
  {
    path: 'wishlist',
    loadComponent: () => import('./pages/my-wishlist/my-wishlist')
  },
  {
    path: '**',
    canActivate: [redirectNearMatch],
    loadComponent: () => import('./pages/not-found/not-found')
  },
];
