import { CanActivateFn, Router } from '@angular/router';
import { inject } from '@angular/core';
import { ROUTES } from '../../models/redirect';

export const redirectNearMatch: CanActivateFn = (route, state) => {
  const router = inject(Router);

  const input = state.url.replace('/', '');

  const closest = ROUTES.find((r) => r.startsWith(input));

  if (closest) {
    const target = closest === 'products' ? 'products/all' : closest;
    router.navigateByUrl('/' + target);
    return false;
  }

  return true;

};
