import { Component, inject } from '@angular/core';
import { RouterLink } from '@angular/router';
import { LocaleStore } from '../../../../assets/locale/locale.store';

@Component({
  selector: 'error-not-found',
  imports: [RouterLink],
  templateUrl: './not-found.html',
  styleUrl: './not-found.scss',
})
export default class NotFound {
  readonly locale = inject(LocaleStore);
}
