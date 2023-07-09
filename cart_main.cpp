#include <iostream>

#include "cart_model.h"
#include <vector>


vector<Product> all_products = {
    Product(1, "apple", 26),
    Product(3, "mango", 16),
    Product(2, "guava", 36),
    Product(5, "banana", 56),
    Product(4, "strawberry", 29),
    Product(6, "pineapple", 20),
};

Product* chooseProduct()
{
    string product_list;
    cout<<"available products"<<endl;

    for(auto product: all_products){
        product_list.append(product.get_display_name());
    }

    cout<<product_list<<endl;
    cout<<"-------------------"<<endl;

    string choice;
    cin>> choice;
    for(int i =0;i<all_products.size();i++)
    {
        if(all_products[i].get_short_name()==choice)
        {
            return &all_products[i];
        }
    }
    cout<< "product is not found"<<endl;
    return NULL;
}

bool Checkout(Cart &cart)
{
    if(cart.is_empty())
    {
        return false;
    }
    int total =cart.get_total();
    cout<<"Pay in Cash Rs ";
    int paid;
    cin>> paid;
    if(paid>= total){
        cout<< "Change : Rs "<<paid-total<<endl;
        cout<< " Thank you for Shopping"<<endl;
        return true;
    }
    else
    {
        cout<< " not enough cash ";
        return false;
    }
}
int main()
{
    // Product p(1, " litchi",100);
    // cout<<p.get_display_name();

    // Item fruit( p,3);
    // cout<< fruit.get_item_info();
    // return 0;

    char action;

    Cart cart;
    while (true)
    {
        cout << "Select an action -  (a)dd item, (v)iew cart, (c) heckout" << endl;
        cin>>action;
        if (action == 'a')
        {
            // Todo: Add to Cart
            //  View all Products + choose product + Add to the Cart-
            Product * product= chooseProduct();
            if(product!= NULL)
            {
                cout<<"added to the cart "<<product->get_display_name()<<endl;
                cart.add_product(*product);
            }
        }
        else if (action == 'v')
        {
            // View the Cart
            cout<<"----------------"<<endl;
            cout<< cart.view_cart();
            cout<<"----------------"<<endl;

        }
        else
        {
            // Checkout
            cart.view_cart();
            if(Checkout(cart))
            {
                break;
            }
        }
    }
    return 0;
}