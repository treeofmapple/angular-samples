import { Component, inject } from '@angular/core';
import { RouterLink } from '@angular/router';
import { LocaleStore } from '../../../../assets/locale/locale.store';

@Component({
  selector: 'error-much-requests',
  imports: [RouterLink],
  templateUrl: './much-requests.html',
  styleUrl: './much-requests.scss',
})
export default class TooMuchRequests {
  readonly locale = inject(LocaleStore);

  reloadPage(): void {
    window.location.reload();
  }
}
