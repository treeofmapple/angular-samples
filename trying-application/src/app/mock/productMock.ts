import { Product } from '../models/product';

export const ProductsMock: Product[] = [
  {
    id: '1',
    name: 'Vulkan X1',
    description: 'High-performance sports car with aggressive design.',
    price: 299.99,
    imageUrl:
      'https://images.unsplash.com/photo-1617814076367-b759c7d7e738?auto=format&fit=crop&w=1600&q=80',
    rating: 5,
    reviewCount: 128,
    inStock: true,
    category: 'car',
  },
  {
    id: '2',
    name: 'Nebula GT',
    description: 'Luxury electric sedan with extended range.',
    price: 549.99,
    imageUrl:
      'https://images.unsplash.com/photo-1619767886558-efdc259cde1a?auto=format&fit=crop&w=1600&q=80',
    rating: 4.7,
    reviewCount: 94,
    inStock: true,
    category: 'car',
  },
  {
    id: '3',
    name: 'Titan Offroad',
    description: 'Rugged SUV built for extreme terrain.',
    price: 479.99,
    imageUrl:
      'https://images.unsplash.com/photo-1549924231-f129b911e442?auto=format&fit=crop&w=1600&q=80',
    rating: 4.5,
    reviewCount: 67,
    inStock: false,
    category: 'car',
  },
  {
    id: '4',
    name: 'Aero Blade Bike',
    description: 'Lightweight aerodynamic racing bicycle.',
    price: 199.99,
    imageUrl:
      'https://images.unsplash.com/photo-1520975922284-9f3f22a4c38b?auto=format&fit=crop&w=1600&q=80',
    rating: 4.8,
    reviewCount: 41,
    inStock: true,
    category: 'bike',
  },
  {
    id: '5',
    name: 'Urban Rider',
    description: 'Comfortable city bike for daily commuting.',
    price: 149.99,
    imageUrl:
      'https://images.unsplash.com/photo-1518655048521-f130df041f66?auto=format&fit=crop&w=1600&q=80',
    rating: 4.3,
    reviewCount: 33,
    inStock: true,
    category: 'bike',
  },
  {
    id: '6',
    name: 'Photon Laptop Pro',
    description: 'Ultra-thin laptop with powerful performance.',
    price: 999.99,
    imageUrl:
      'https://images.unsplash.com/photo-1517336714731-489689fd1ca8?auto=format&fit=crop&w=1600&q=80',
    rating: 4.9,
    reviewCount: 211,
    inStock: true,
    category: 'electronics',
  },
  {
    id: '7',
    name: 'Nova Smartphone',
    description: 'Flagship smartphone with stunning camera.',
    price: 699.99,
    imageUrl:
      'https://images.unsplash.com/photo-1511707171634-5f897ff02aa9?auto=format&fit=crop&w=1600&q=80',
    rating: 4.6,
    reviewCount: 178,
    inStock: true,
    category: 'electronics',
  },
  {
    id: '8',
    name: 'Echo Wireless Headphones',
    description: 'Noise-cancelling over-ear headphones.',
    price: 179.99,
    imageUrl:
      'https://images.unsplash.com/photo-1518441984850-cbdb0b3a04b4?auto=format&fit=crop&w=1600&q=80',
    rating: 4.4,
    reviewCount: 89,
    inStock: false,
    category: 'electronics',
  },
];
