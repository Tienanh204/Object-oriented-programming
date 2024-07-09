#include"Function.h"


int main()
{
	Prince prince;
	prince.registerGate(new BusinessGate());
	prince.registerGate(new AcademicGate());
	prince.registerGate(new Power());
	//Cau 1
	cout << "************** GAME **************" << endl;
	cout << "1. Business gate" << endl;
	cout << "2. Academic gate" << endl;
	cout << "3. Power gate" << endl;
	cout << "**********************************" << endl << endl;
	cout << "So luong cong: ";
	int numGate; cin >> numGate;
	vector<Gate*> gate;

	for (int i = 0; i < numGate; i++) {
		cout << "Type gate: ";
		int typeGate; cin >> typeGate;
		Gate* tempGate = prince.getGate(typeGate);
		tempGate->input();
		gate.push_back(tempGate);
	}

	//Cau 2
	int amount = 0;
	int iq = 0;
	int power = 0;
	cout << "************** Prince's Information **************" << endl;
	cout << "Money: "; cin >> amount;
	cout << "IQ: "; cin >> iq;
	cout << "Power: "; cin >> power;
	cout << "**************************************************" << endl << endl;

	int i = 0;
	for (auto& it : gate) {
		cout << "<Challenge " << i + 1 << ">" << endl;
		if (it->getTypeGate() == 1) {
			amount -= it->getFeatureGate();
			if (amount < 0)
			{
				cout << "The prince failed at Business Gate " << i + 1 << endl;
				return 0;
			}
			else
			{
				cout << "The prince passed Business Gate " << i + 1 << endl;
			}
		}
		if (it->getTypeGate() == 2)
		{
			if (iq >= it->getFeatureGate())
			{
				cout << "The prince passed Academic Gate " << i + 1 << endl;
			}
			else
			{
				cout << "The prince failed at Academic Gate " << i + 1 << endl;
				return 0;
			}
		}
		if (it->getTypeGate() == 3)
		{
			power -= it->getFeatureGate();
			if (power < 0)
			{
				cout << "The prince failed at Power Gate " << i + 1 << endl;
				return 0;
			}
			else
			{
				cout << "The prince passed Power Gate " << i + 1 << endl;
			}
		}
		cout << "-> Current parameters [amount, iq, power]: " << "[" << amount << ", " << iq << ", " << power << "]" << endl << endl;
		if (i == numGate - 1)
		{
			cout << "**************************************************" << endl;
			cout << "|        The prince saved the princess           |" << endl;
			cout << "**************************************************" << endl;
			return 0;
		}
		i++;
	}
}