# Unit Test Generator

A tool for automatically generating, refining, and analyzing C++ unit tests using a local LLaMA model (via llama-cpp-python).

**Note:** While this generator supports any C++ project, the tests provided in this repository have been generated for the C++ [OrgChartApi](https://github.com/keploy/orgChartApi) project.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
  - [Generate and Refine Tests](#generate-and-refine-tests)
  - [Coverage Analysis](#coverage-analysis)
- [C++ Project Under Test: orgChartApi](#c-project-orgchartapi)
  - [Build](#build)
  - [Run Tests](#run-tests)
  - [Database Setup](#database-setup)
- [Scripts](#scripts)
- [License](#license)

## Prerequisites

- Python 3.8+
- CMake ≥ 3.15 and a C++17-capable compiler (g++ or clang++)
- OpenSSL (development libraries)
- A local GGUF model file for LLaMA (e.g., `Gemma 2B IT.gguf`) — download it from Hugging Face and place it in the project root.

- A C++ project directory under test in the root of this repo. For example, to test the OrgChartApi project:
  ```bash
  git clone https://github.com/keploy/orgChartApi.git orgChartApi
  ```
  You can clone any other C++ project similarly; just update the `project.path` in `generator/config.yaml` to point to its folder.

## Installation

### 1. System Dependencies

On macOS (using Homebrew):
```bash
brew update
brew install cmake openssl mysql
```

On Ubuntu/Debian:
```bash
sudo apt update
sudo apt install build-essential cmake libssl-dev mysql-client
```

### 2. Python Environment

```bash
python3 -m venv venv
source venv/bin/activate
pip install --upgrade pip
pip install -r requirements.txt
```

### 3. LLaMA Model

Download the `Gemma 2B IT.gguf` model from Hugging Face and place it in the project root:
```bash
pip install huggingface-hub
huggingface-cli login
huggingface-cli repo download your-org/Gemma-2B-IT --filename "Gemma 2B IT.gguf"
```

### 4. Initial Test Generation

```bash
./run.sh
```

### 5. C++ Build Tools

Ensure the C++ project builds correctly:
```bash
cd orgChartApi
./build.sh
```

## Configuration

Update `generator/config.yaml` to match your setup:

```yaml
project:
  path: orgChartApi          # Path to the orgChartApi directory
model:
  type: local_llama
  model_path: "Gemma 2B IT.gguf"  # Path to your local LLaMA GGUF model
```

## Usage

### Generate and Refine Tests

A helper script (`run.sh`) will generate initial tests, refine them, and provide coverage improvement suggestions:

```bash
./run.sh
```

- Generated test files appear in the `tests/` directory.
- Coverage suggestions are saved to `coverage_analysis.md`.

### Coverage Analysis

To run coverage analysis alone:

```bash
python3 generator/generate_tests.py
```

This will read existing tests and source files, then output recommendations in `coverage_analysis.md`.

## C++ Project Under Test: orgChartApi

### Build

```bash
cd orgChartApi
mkdir -p build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
      -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl \
      -DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib \
      ..
make
```

Alternatively, run the provided build script:

```bash
cd orgChartApi
./build.sh
```

### Run Tests

Inside the build directory:

```bash
cd orgChartApi/build
ctest --output-on-failure
```

Or execute individual test binaries (e.g., `test_controllers`, `test_main`).

### Database Setup

SQL scripts for DB creation and seeding are in `orgChartApi/scripts`:

```bash
# Create database
mysql -u <user> -p < scripts/create_db.sql

# Seed database
mysql -u <user> -p < scripts/seed_db.sql
```

## Scripts

- `run.sh`: Automates test generation, refinement, and coverage analysis.
- `orgChartApi/build.sh`: Builds the C++ project with CMake.
- `orgChartApi/commands.sh`: Alternative CMake invocation.
- `orgChartApi/scripts/`: SQL scripts for database setup.

## License

This project is licensed under the [MIT License](LICENSE).
