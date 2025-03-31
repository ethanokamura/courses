#!/bin/bash
make -C MazeSolver/

values=("10" "50" "100" "500" "1000" "5000")

echo "#############################"

for i in "${values[@]}"; do
  # Define file paths
  INPUT_FILE="Examples/Mazes/$i.txt"
  EXPECTED_OUTPUT="Examples/Paths/$i.txt"
  ACTUAL_OUTPUT="Data/Paths/$i.txt"

  # Run Sparse and save the output to out.txt
  echo "Running data/$INPUT_FILE"

  # valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s 
  ./MazeSolver/Solver "$INPUT_FILE" "$ACTUAL_OUTPUT"

  # Compare output with expected output using diff -Z
  if [ -f "$EXPECTED_OUTPUT" ]; then
    echo "Comparing output of $ACTUAL_OUTPUT with $EXPECTED_OUTPUT"
    diff -Z "$ACTUAL_OUTPUT" "$EXPECTED_OUTPUT"

    if [ $? -eq 0 ]; then
      echo "✅ Test passed: Found Correct Path"
    else
      echo "❌ Test failed: Incorrect Path"
    fi
  else
    echo "⚠️ Warning: Expected output file '$EXPECTED_OUTPUT' not found!"
  fi
  echo "#############################"
done

make clean -C MazeSolver/