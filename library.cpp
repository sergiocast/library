#include <iostream>
#include <map>
#include <fstream>
#include<algorithm>
#include <vector>

//Read from a text file named phoneno.txt
//Use standard library algorithms to do the following
//Read the file into a map, print the maps size
//Print the count of phone numbers with area code 347
//Print ID of every person with phone number 212-536-6331
//Create a vector that stores all phone numbers with area code 212, from the map. Print the size of the vector.
//Create another vector with all duplicates of 212 numbers removed. Print the size of this vector.

using namespace std;


int main(){



map<int,string> Map;

int count =0;


   ifstream myfile;
   string word;

    myfile.open ("phoneno.txt");


  if (myfile.is_open())
    {

      while(myfile >> word)
      {
		int num;
		if(word.size() == 6){
	    word.erase(remove(word.begin(), word.end(), ','), word.end());
        num = stoi(word);
	    Map[num];
		}
		else{
			string str2 = word.substr (0,3);
			Map[num] = word;
			if (str2 == "347")
				count++;
		}


}
      myfile.close();



}

    else cout << "Unable to open file";


     cout<<"Size of the map: "<<  Map.size() << endl;

     cout<<"Count of phone# with area code 347: "<< count <<endl;

 	cout<<"The ID(s) with the given phone#: ";

  for(auto x: Map){
 	  if (x.second == "212-536-6331")
   	cout<< x.first << " ";
}
     cout<< ""<< endl;


  vector <string> vec;

  for(auto y: Map){
	  string a = y.second.substr (0,3);
	  	if (a == "212")
	      vec.push_back(y.second);

  }

   cout<<"Size of the vector with all (212) numbers: " << vec.size() << endl;


     vector <string> vec2;

   for (int i=0; i <vec.size(); i++){
 	      		vec2.insert(vec2.begin(), vec[i]);

	}



     sort(vec2.begin(), vec2.end());
     vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());




    cout<<"Size of the vector with unique (212) numbers: " << vec2.size();





}




