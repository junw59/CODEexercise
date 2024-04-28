#include <iostream>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};


int main() {
    int num;
    while(cin >> num){
        getchar();
        ListNode *lt=new ListNode;
        ListNode *dummy=new ListNode;
        dummy->m_pNext=lt;
        int a;
        cin >> a;
        // cin >> (lt->m_nKey);
        lt->m_nKey =a;
        num--;
        while (num--){
            cin >> a;
            lt->m_pNext = new ListNode;
            lt=lt->m_pNext;
            lt->m_nKey=a;
            lt->m_pNext=nullptr;
        }


        // lt = dummy->m_pNext;
        // while(lt!=nullptr){
        //     cout << lt->m_nKey << " ;";
        //     lt=lt->m_pNext;
        // }

        int k;
        cin >> k;

        lt = dummy->m_pNext;
        ListNode *lt2 = dummy->m_pNext;
        while(k--){
            lt=lt->m_pNext;
        }
        // cout << "del:" << lt2->m_nKey << lt->m_nKey << endl;

        while(lt!=nullptr){
            lt=lt->m_pNext;
            lt2=lt2->m_pNext;
        }

        cout << lt2->m_nKey << endl;
    }


}
// 64 位输出请用 printf("%lld")