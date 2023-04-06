#include <iostream>
using namespace std;

int main()
{
    float SampleWeight = 3.15, PalletWeight = 25, Weight, WeightStack;
    int InStack = 20,  NumberStack, NumberSample, Sample;
    cout << "Enter total weight: ";
    cin >> Weight;
    WeightStack = Weight - PalletWeight - (SampleWeight * InStack);
    NumberStack = WeightStack/InStack;
    Sample = NumberStack * InStack;
    cout << "Thrive sample packs stacked: " << NumberStack << endl;
    cout << "Actual pallet weight : "<<WeightStack<<endl;
    cout << "Number of samples: " << Sample << endl;
    return 0;
}
