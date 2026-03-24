// Cho một danh sách liên kết, hãy hoán đổi hai phần tử liền kề nhau và trả về phần tử đầu tiên của danh sách. Bạn phải giải quyết bài toán mà không được thay đổi giá trị trong các phần tử của danh sách (nghĩa là, chỉ có bản thân các phần tử mới được thay đổi).
// Ví dụ 1:
// Đầu vào: head = [1,2,3,4]
// Kết quả đầu ra: [2,1,4,3]
class Solution {
public:    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;
        return second;
    }
};