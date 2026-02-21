import { Component, input, output } from '@angular/core';
import { Product } from '../../models/product';
import { MatIcon } from '@angular/material/icon';
import { MatButton } from '@angular/material/button';

@Component({
  selector: 'app-product-card',
  standalone: true,
  imports: [MatIcon, MatButton],
  templateUrl: './product-card.html',
})
export class ProductCard {
  product = input.required<Product>();

  addToCartClicked = output<Product>();
}
