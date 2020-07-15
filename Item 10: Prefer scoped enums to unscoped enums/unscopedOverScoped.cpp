/*
    There's a case when using unscoped over scoped is benefitial, reason being
    implicit type conversion of enumerators in unscoped enums
    
*/

#include<iostream>
#include<tuple>

using namespace std;
using UserInfo = tuple<string, string, size_t>;

int main(){
	
	enum user_info_fields_unscoped {ui_name, ui_email, ui_reputation};
	enum class user_info_fields_scoped {ui_name, ui_email, ui_reputation};
	
	UserInfo u_info{"Dhruv", "abc@xyz.com", 10};
	
	//get email through scoped and unscoped enums
	
	auto email = get<ui_email>(u_info);
	cout << email << endl;
	
	//inconvenient to type such big thing, have to cased to signed integer since no implicit conversion of enumerators
	email = get<static_cast<size_t>(user_info_fields_scoped::ui_email)>(u_info);
	cout << email << endl;
	
	return 0;
}
