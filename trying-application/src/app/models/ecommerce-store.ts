import { computed } from '@angular/core';
import { Product } from './product';
import {
  patchState,
  signalMethod,
  signalStore,
  withComputed,
  withMethods,
  withState,
} from '@ngrx/signals';
import { ProductsMock } from '../mock/productMock';

export type EcommerceState = {
  products: Product[];
  category: string;
  wishlistItems: Product[];
};

export const EcommerceStore = signalStore(
  {
    providedIn: 'root',
  },
  withState<EcommerceState>({
    products: ProductsMock,
    category: 'all',
    wishlistItems: [],
  } as EcommerceState),
  withComputed(({ category, products }) => ({
    availableCategories: computed(() => ['all', ...new Set(products().map((p) => p.category))]),
    filteredProducts: computed(() => {
      const current = category().toLowerCase();
      return current === 'all' ? products() : products().filter((p) => p.category === current);
    }),
  })),

  withMethods((store) => ({
    setCategory: (category: string) => {
      patchState(store, { category });
    },
    addToWishlist: (product: Product) => {
      const exists = store.wishlistItems().some((p) => p.id === product.id);

      if (!exists) {
        patchState(store, (state) => ({
          wishlistItems: [...state.wishlistItems, product],
        }));
      }
    },
  })),
);
