Plan:

Created a file system that stored in multiple systems and if any system crashes we can added another system in the chain and when we add our system in chain they auto company
all the file system files!

Require at least 3 machines or more with odd number of chunk servers in the chain , if even number of systems are in chain it may leads to stalemate.
With a heartbeat protocol [to check health of other chunk servers in the chain].
We don't replicate all the chunks on every server but we give a replication factor (example 3) to store them on multiple server ? ( to reduce writing latency and storage wastage)


![image](https://github.com/user-attachments/assets/dcfde23c-b432-4e60-82d2-dac6a5e5f554)

It should be both server and rack aware ! 
