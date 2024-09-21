# Simple Order Book in C++

This project implements a basic order book system in C++ for educational purposes.

## Features

- **Add Orders**: Supports adding buy and sell orders.
- **Order Matching**: Automatically matches orders based on price and time priority.
- **Display Order Book**: View the current buy and sell orders.

## Getting Started

### Prerequisites

- C++11 compatible compiler (e.g., g++, clang++)
- Terminal or command prompt

### Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/orderbook.git
   cd orderbook
   ```

2. **Compile the Program**

   ```bash
   g++ -std=c++11 -o orderbook main.cpp Order.cpp OrderBook.cpp
   ```

3. **Run the Program**

```bash
./orderbook
```

## Usage

1. **Add Orders**:
   - Enter `1` to add a buy order.
   - Enter `2` to add a sell order.
