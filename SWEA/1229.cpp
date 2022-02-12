#include <iostream>
#include <list>
using namespace std;
 
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int test_case;
    int T;
 
    cin >> T;
 
    for ( test_case = 1; test_case <= T; ++test_case )
    {
        list<int> l;
        int n;
        cin >> n;
        while ( n-- )
        {
            int num;
            cin >> num;
            l.push_back(num);
        }
 
        cin >> n;
 
        while ( n-- )
        {
            char cmd;
            cin >> cmd;
         
            int x, y, num;
            cin >> x >> y;
 
            if ( cmd == 'I' )
            {
                list<int> list2;
                while ( y-- )
                {
                    cin >> num;
                    list2.push_back(num);
                }
                list<int>::iterator iter = l.begin();
                advance(iter, x);
                l.splice(iter, list2);
 
            }
            else if ( cmd == 'D' )
            {
                list<int>::iterator iter1, iter2;
                iter1 = iter2 = l.begin();
                advance(iter1, x);
                advance(iter2, x + y);
                l.erase(iter1, iter2);
            }
        }
 
 
        cout << "#" << test_case << " ";
        int cnt = 1;
        for ( int num : l )
        {
            cout << num << " ";
            if ( cnt++ == 10 ) break;
        }
        cout << '\n';
    }
    return 0;
}