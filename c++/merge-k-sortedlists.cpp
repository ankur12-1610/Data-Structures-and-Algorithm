# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        store = {}
        for lst in lists:
            start = lst
            while start:
                curr = start
                while curr.next and curr.next.val == start.val:
                        curr = curr.next
                try:
                    sect_head, sect_tail = store[start.val]
                except KeyError:
                    store[start.val] = [start, curr]
                else:
                    sect_tail.next = start
                    store[start.val][1] = curr
                start = curr.next
        tail = None
        head = None
        for key in sorted(store.keys()):
            front = store[key][0]
            if not tail:
                head = front
            else:
                tail.next = front
            tail = store[key][1]
        return head
