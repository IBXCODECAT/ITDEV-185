#pragma once
// Compile guard to prevent multiple includes for compilers that do not support #pragma once
#define PRODUCTMANAGER_H
#ifdef PRODUCTMANAGER_H

/// <summary>
/// A wrapper class to manage products in the store
/// </summary>
static class ProductManager
{
public:

	/// <summary>
	/// List all products in the store
	/// </summary>
	static void listProducts();

	/// <summary>
	/// Add a product to the store
	/// </summary>
	static void addProduct();

	/// <summary>
	/// Update a product in the store
	/// </summary>
	static void updateProduct();

	/// <summary>
	/// Remove a product from the store
	/// </summary>
	static void removeProduct();

	/// <summary>
	/// Save the products to a file
	/// </summary>
	static void saveProducts();

	/// <summary>
	/// Delete all products from the store that fit the given category by some value
	/// </summary>
	static void discountCategory();

	/// <summary>
	/// Discount all products from the store that fit the given category by a percentage
	/// </summary>
	static void discountCategoryByPercentage();
};

#endif // PRODUCTMANAGER_H