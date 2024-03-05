
func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil || k == 1 {
		return head
	}

	// Define a helper function to reverse a sublist of length k
	reverse := func(head *ListNode, k int) (*ListNode, *ListNode) {
		var prev, nextNode *ListNode
		curr := head
		for i := 0; i < k && curr != nil; i++ {
			nextNode = curr.Next
			curr.Next = prev
			prev = curr
			curr = nextNode
		}
		return prev, head // Change nextNode to head as we want to return the original head of the reversed sublist
	}

	dummy := &ListNode{Next: head}
	prevTail := dummy

	for head != nil {
		currHead := head
		// Check if there are k nodes remaining
		checkNode := head
		for i := 0; i < k; i++ {
			if checkNode == nil {
				// If less than k nodes remaining, break the loop
				prevTail.Next = currHead
				return dummy.Next
			}
			checkNode = checkNode.Next
		}
		for i := 0; i < k-1 && head != nil; i++ {
			head = head.Next
		}
		nextHead := head.Next
		head.Next = nil // Cut off the sublist

		// Reverse the current group
		reversedHead, reversedTail := reverse(currHead, k)

		// Connect the reversed sublist to the previous sublist
		prevTail.Next = reversedHead
		prevTail = reversedTail

		// Move to the next group
		head = nextHead
	}

	return dummy.Next
}