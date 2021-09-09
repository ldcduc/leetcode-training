/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverse(node *ListNode, prev *ListNode) *ListNode {
    if node != nil {
        if (node.Next != nil) {
            next := node.Next
            node.Next = prev
            return reverse(next, node)
        } else {
            node.Next = prev;
            return node;
        }
    }
    return nil
}

func reverseList(head *ListNode) *ListNode {
    return reverse(head, nil);
}
