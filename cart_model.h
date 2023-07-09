// making three classes : product,  item , cart;
using namespace std;
#include <string> 
#include <unordered_map>
class Item;
class Cart;
class Product{
    int id ;
    string name;
    int price;

    public:

    // constructor
    Product()
    {

    }
    Product(int un_id,string name, int price)
    {
        id= un_id;
        this->name= name;
        this-> price= price;
    }

    string get_display_name(){
        return name + ": Rs" + to_string(price) + "\n";
    }

    string get_short_name(){
        return name.substr(0,1);
    }
    friend class Item;
    friend class Cart;
} ;


class Item{
    Product product;
    int quantity;

    public:
    // constructor
    Item() {}
    
    Item (Product p,int q):product(p),quantity(q){}


    int item_get_price(){
        return quantity* product.price;
    }

    string get_item_info(){
        return to_string(quantity)+ "x " +product.name + " Rs. " + to_string(quantity *product.price) + '\n';
    }
    friend class Cart;
};

class Cart {
    unordered_map<int,Item> items;
    public:
    void add_product(Product product){
        if(items.count(product.id)==0)
        {
            Item newitem(product,1);
            items[product.id] =newitem; 
        }
        else
        {
            items[product.id].quantity +=1;
        }
    }
    int get_total(){
        int total= 0;
        for(auto itempair :items)
        {
            auto item = itempair.second;
            total+= item.item_get_price();
        }
        return total;
    }

    string view_cart()
    {
        if(items.empty())
        {
            return " cart is empty";
        }
        string  itemized_list;
        int cart_total = get_total();

        for(auto itempair:items){
            auto item = itempair.second;
            itemized_list.append(item.get_item_info());
        }

        return itemized_list + "\n Total amount : Rs. " + to_string(cart_total) + '\n';
    }

    bool is_empty()
    {
        return items.empty();
    }


};