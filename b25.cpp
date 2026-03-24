// Cho trước headmột danh sách liên kết, hãy đảo ngược các phần tử của danh sách ktừng phần tử một và trả về danh sách đã được sửa đổi .

// klà một số nguyên dương và nhỏ hơn hoặc bằng độ dài của danh sách liên kết. Nếu số lượng nút không phải là bội số của kthì các nút bị bỏ lại cuối cùng sẽ vẫn giữ nguyên.

// Bạn không được phép thay đổi giá trị trong các nút của danh sách, chỉ có thể thay đổi chính các nút đó.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            if (!node) return head;
            node = node->next;
        }
        ListNode* prev = reverseKGroup(node, k);
        while (head != node) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};