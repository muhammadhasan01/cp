#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myFunction(int i){
  cout << i;
}

bool isOdd(int n){
  return n%2;
}

int main(){
  int arr[10] = {9,5,4,6,2,1,3,7,8,0};
  vector<int> v;
  v.assign(arr,arr+10);
  // or v(arr,arr+10);
  
  cout << "The Array is :\n";
  for_each(arr,arr+10,myFunction);
  cout << endl << endl;
  
  vector<int>:: iterator it;
  it = v.begin();
  cout << "Example of an iterator on vector :\n";
  cout << "*(it+5) = "<<*(it+5) << endl << endl;
  v.clear();
  
  cout << "The Max and Min Elements\n";
  cout << *max_element(arr,arr+10) << endl;
  cout << *min_element(arr,arr+10) << endl;
  cout << endl;
  
  //Sorting 
  sort(arr,arr+10);
  //reverse
  reverse(arr,arr+10);
  
  // below only works on c++11
  // any_of/all_of/none_of(arr,arr+10,<bool condition> such as [](int n){return n%2;})
  
  
  //Using for_each
  cout << "The reversed sorted array contains :\n";
  for_each(arr,arr+10,myFunction);
  cout << "\n\n";
  
  //using find as find returns an iterator
  cout << "Input an element you want to find: ";
  int x;
  cin >> x;
  int *p = find(arr,arr+10,x);
  if(p != arr+10){
    cout << "The array does contain " << *p << endl;
  } else {
    cout << "The array does not contain " << x << endl;
  }
  cout << endl;
  
  //using find_if which also returns an iterator
  int *iter = find_if(arr,arr+10,isOdd);
  if(iter != arr+10){
    cout << "The first odd value is " << *iter << endl;
  } else {
    cout << "It doesn't have any odd value" << endl;
  }
  cout << endl;
  
  // replace
  cout << "Let's replace 0 with 10 and re-sort things up!\n";
  replace(arr,arr+10,0,10);
  sort(arr,arr+10);
  for_each(arr,arr+10,myFunction);
  
  // replace_if & counts
  cout << "\n\nNow let's replace the odd number into zero\n";
  replace_if(arr,arr+10,isOdd,0);
  for_each(arr,arr+10,myFunction);
  int many = count(arr,arr+10,0);
  //count_if(arr,arr+10,function);
  cout << "\n*There are " << many << " zeros";
  
  
  // remove (works on vector), note that remove returns an iterator while also changing the vector
  cout << "\n\nNow we'll erase all the zero elements\n";
  v.assign(arr,arr+10);
  
  //first we'll remove
  vector<int>::iterator pos = remove(v.begin(),v.end(),0);
  //returns an iterator that follows the element not removed
  //for_each(v.begin(),v.end(),myFunction);
  // prints 24810608010
  v.erase(pos,v.end());
  for_each(v.begin(),v.end(),myFunction);
  cout << endl;
  
  // Unique
  v.clear();
  int arrnew[5] = {1,1,2,2,2};
  v.assign(arrnew,arrnew+5);
  
  cout << "\nThis is a new vector :\n";
  for_each(v.begin(),v.end(),myFunction);
  cout << endl;
  //vector<int>::iterator it;
  it = unique(v.begin(),v.end());
  cout << "\nThis is a new vector :\n";
  for_each(v.begin(),v.end(),myFunction);
  cout << endl;
  v.resize(distance(it,v.end()));
  for(it = v.begin(); it != v.end(); it++){
    cout << *it;
  }
  cout << endl;
  return 0;
}