import { Component, computed, effect, inject, input, signal } from '@angular/core';
import { Product } from '../../models/product';
import { ProductCard } from '../../components/product-card/product-card';
import { MatSidenavContainer, MatSidenavContent, MatSidenav } from '@angular/material/sidenav';
import { MatListItem, MatNavList } from '@angular/material/list';
import { RouterLink } from '@angular/router';
import { EcommerceStore } from '../../models/ecommerce-store';

@Component({
  selector: 'app-products-grid',
  standalone: true,
  imports: [
    ProductCard,
    MatSidenavContainer,
    MatSidenavContent,
    MatSidenav,
    MatNavList,
    MatListItem,
    RouterLink,
  ],
  templateUrl: './products-grid.html',
})
export default class ProductsGrid {
  category = input<string>('all');
  store = inject(EcommerceStore);

  constructor() {
    effect(() => {
      this.store.setCategory(this.category());
    });
  }

  // categories = signal<string[]>(['all', 'electronics', 'clothing', 'accessories', 'home']);

  addToCart(product: Product) {}
}
