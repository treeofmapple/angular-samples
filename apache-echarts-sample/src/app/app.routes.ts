import { Routes } from '@angular/router';
import { redirectNearMatch } from './core/config/tools/redirect-match';

export const routes: Routes = [
  {
    path: '',
    pathMatch: 'full',
    redirectTo: 'home',
  },
  {
    path: 'error',
    children: [
      {
        path: '401',
        loadComponent: () =>
          import('./pages/errors/nonauthorized/nonauthorized').then((m) => m.default),
        data: { hideLayout: true },
      },
      {
        path: '404',
        loadComponent: () => import('./pages/errors/not-found/not-found').then((m) => m.default),
        data: { hideLayout: true },
      },
      {
        path: '429',
        loadComponent: () =>
          import('./pages/errors/too-much-requests/much-requests').then((m) => m.default),
        data: { hideLayout: true },
      },
      {
        path: '500',
        loadComponent: () =>
          import('./pages/errors/internal-server/internal-server').then((m) => m.default),
        data: { hideLayout: true },
      },
    ],
  },
  {
    path: '**',
    canActivate: [redirectNearMatch],
    loadComponent: () => import('./pages/errors/not-found/not-found').then((m) => m.default),
  },
];
