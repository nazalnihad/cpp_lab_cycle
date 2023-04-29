#include <iostream>
using namespace std;
class election
{
    const int candidates = 5;
    int votes[5] = {0};
    int spoilt = 0;

public:
    election() {}
    void getvotes()
    {
        int ballot;
        while (ballot != 0)
        {
            cout << "0 - if done \nEnter the ballot number : ";
            cin >> ballot;
            if (ballot > 0 && ballot <= 5)
            {
                votes[ballot - 1]++;
            }
            else
            {
                spoilt++;
            }
        }
    }

    void show()
    {
        cout << endl;
        int winner = 0, win;
        string yay;
        for (int i = 0; i < candidates; i++)
        {
            if (votes[i] > winner)
            {
                winner = votes[i];
                win = i;
            }
            cout << "candidate " << i + 1 << " votes = " << votes[i] << "\n";
        }
        cout << "And the winner is candidate " << win + 1 << " with " << votes[win] << "votes \n";
        cout << "No of spoilt votes are " << spoilt - 1 << "\n";
    }
};

int main()
{
    election a;
    a.getvotes();
    a.show();

    return 0;
}