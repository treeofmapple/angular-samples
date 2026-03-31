import { CanActivateFn, Router } from '@angular/router';
import { inject } from '@angular/core';
import { ROUTES } from './redirect';

export const redirectNearMatch: CanActivateFn = (route, state) => {
  const router = inject(Router);

  const input = state.url.replace('/', '');

  const closest = ROUTES.find((r) => r.startsWith(input));

  if (closest) {
    router.navigateByUrl('/' + closest);
    return false;
  }

  return true;

};
