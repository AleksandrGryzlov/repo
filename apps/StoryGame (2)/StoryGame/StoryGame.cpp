#include <iostream>
using namespace std;

int main()
{
    string Name, City, College, Profession, Animal, PetName;
    int Age;
    cout << "Please enter name: ";
    cin >> Name;
    cout << "Please enter age: ";
    cin >> Age;
    cout << "Please enter name of the city: ";
    cin >> City;
    cout << "Please enter name of the college: ";
    cin >> College;
    cout << "Please enter name of the profession: ";
    cin >> Profession;
    cout << "Please enter type of animal: ";
    cin >> Animal;
    cout << "Please enter name of the pet: ";
    cin >> PetName;
    cout << "There once was a person named " << Name << " who lived in " << City << ".At the age of " << Age << ", " << Name << " went to college at " << College;
    cout << "." << Name << " graduatedand went to work as a " << Profession << ".Then, ";
    cout << Name << " adopted a " << Animal << " named " << PetName << ".They both lived happily ever after." << endl;
    return 0;
}