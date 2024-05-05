#pragma once
#define PRODUCTMANAGER_H
#ifdef PRODUCTMANAGER_H

class ProductManager
{
public:
	ProductManager();
	~ProductManager();
	static void listProducts();
	static void addProduct();
	static void updateProduct();
	static void removeProduct();
	static void saveProducts();
};

#endif