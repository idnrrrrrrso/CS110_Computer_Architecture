1. 5位offset, 32 bytes each page

2. 找TLB里有没有

   - 如果没有，找page table
     - if valid bit == 0, page fault
       - if memory has empty space, fill the first available frame. Write page table and TLB
       - else, full memory. LRU evict and replace. Write page table and TLB.
     - if valid bit == 1, 看frame numer,去访问physical memory, write TLB
   - 如果有，直接去page frame 对应的offset处访问内存
   
   

---

00 ok

20 ok

40 ok

60 ok

80 ok

a0

c0

e0

00

20

前4次依次访问4个不同的page frame

后4次也是，且每次replace掉前4次中的

所以最后两次也miss了

---

增加physical memory 大小，这样第4到8次就不会overwrite之前的page frame,这样就不会导致最后两次的page fault