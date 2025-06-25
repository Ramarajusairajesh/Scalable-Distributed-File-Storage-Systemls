# Distributed File Grid (Work in Progress)

## Project Summary

Built a distributed file storage system to reduce read/write latency and ensure fault-tolerant data redundancy across unreliable nodes.

- Designed a high-throughput system using asynchronous, multithreaded I/O to split files into 64 MB chunks with configurable replication.
- Implemented a head server to manage metadata and monitor node health via heartbeat signals; auto-triggered re-replication on failure.
- Enabled high availability by deploying a health-checking service on a separate cluster with standby quorum and leader election to ensure continuous operation.
- Used Protocol Buffers (Protobuf) for efficient data serialization in heartbeat signals, metadata exchange, inter-node communication, and cluster coordination.
- Achieved 2× lower latency and zero data loss during simulated multi-node failures in test environments.

---

## Features
- Distributed, fault-tolerant file storage
- Asynchronous, multithreaded I/O for high throughput
- Files split into 64 MB chunks with configurable replication factor
- Head server for metadata management and node health monitoring
- Heartbeat protocol for health checking and auto re-replication
- Health-checking service with leader election for high availability
- Efficient inter-node communication using Protocol Buffers
- Server and rack awareness for intelligent data placement

---

## Architecture Overview

![image](https://github.com/user-attachments/assets/dcfde23c-b432-4e60-82d2-dac6a5e5f554)

- **Head Server:** Manages metadata, coordinates chunk servers, and monitors health.
- **Chunk Servers:** Store file chunks, handle replication, and respond to health checks.
- **Health-Checking Service:** Runs on a separate cluster, uses leader election for continuous monitoring.
- **Protocol Buffers:** Used for all structured communication between nodes.

---

## Requirements
- At least 3 machines (preferably an odd number of chunk servers to avoid stalemate)
- C++17 or later
- Python 3.8+ (for tooling and PyInstaller, if using the Python interface)
- [Protocol Buffers Compiler (protoc)](https://developers.google.com/protocol-buffers)

---

## Installation & Offline Usage

### 1. Clone the Repository
```bash
git clone https://github.com/Stability-AI/stable-fast-3d.git
cd stable-fast-3d
```

### 2. Build the Project
- Use the provided `Makefile` to build C++ components:
  ```bash
  make
  ```
- Ensure `protoc` is installed and run to generate C++ source from `.proto` files:
  ```bash
  protoc -I=protos --cpp_out=include protos/heat_beat.proto
  ```

### 3. (Optional) Build a Standalone Executable with PyInstaller
If you have a Python interface or tools:
```bash
pip install -r requirements.txt
pip install pyinstaller
pyinstaller --onefile --add-data "model_weights;model_weights" main.py
```
- The standalone executable will be in the `dist/` folder.

### 4. Run the System
- Start the head server, chunk servers, and health-checking service as described in the documentation or scripts.
- Add new nodes to the chain as needed; the system will auto-synchronize files and maintain redundancy.

---

## Usage Notes
- The system requires at least 3 chunk servers for proper operation.
- Replication factor is configurable (default: 3).
- Heartbeat protocol ensures failed nodes are detected and data is re-replicated automatically.
- All inter-node communication uses Protocol Buffers for efficiency and versioning.

---

## Troubleshooting
- **Missing Dependencies:** Ensure all system and Python dependencies are installed offline as needed.
- **Model Weights Not Found:** Place required model/data files in the correct directory or bundle them with PyInstaller.
- **Stalemate:** Use an odd number of chunk servers to avoid split-brain scenarios.

---

## Acknowledgments
- Inspired by distributed file systems such as GFS and HDFS.
- Uses [Protocol Buffers](https://developers.google.com/protocol-buffers) for serialization.

---

## License
This project is open-source and a work in progress. Contributions are welcome!
