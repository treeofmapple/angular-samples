import { Component, inject } from '@angular/core';
import { RouterLink } from '@angular/router';
import { LocaleStore } from '../../../../assets/locale/locale.store';

@Component({
  selector: 'error-not-authorized',
  imports: [RouterLink],
  templateUrl: './nonauthorized.html',
  styleUrl: './nonauthorized.scss',
})
export default class NotAuthorized {
  readonly locale = inject(LocaleStore);
}
