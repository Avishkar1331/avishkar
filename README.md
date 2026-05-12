# Hybrid Inventory Manager

## Build
make

## Run
./app

## Features
- Add item
- View item
- Update item
- Delete item (soft delete)
- List items

## Test Cases
- Added 3 items → restart → data persists
- Updated item → restart → changes saved
- Deleted item → not visible
- Duplicate ID rejected
- View by ID works