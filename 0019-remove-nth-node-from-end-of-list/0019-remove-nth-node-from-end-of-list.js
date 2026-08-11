var removeNthFromEnd = function(head, n) {
    const dummy = new ListNode(0);
    dummy.next = head;

    let slow = dummy;
    let fast = dummy;

    // Move fast n + 1 steps ahead
    for (let i = 0; i <= n; i++) {
        fast = fast.next;
    }

    // Move both pointers
    while (fast !== null) {
        slow = slow.next;
        fast = fast.next;
    }

    // Remove the node
    slow.next = slow.next.next;

    return dummy.next;
};