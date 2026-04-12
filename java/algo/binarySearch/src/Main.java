static class Solution {
  static int binarySearch(int[] nums, int target) {
    int start = 0, end = nums.length - 1;

    while (start <= end) {
      final int mid = start + (end - start) / 2;

      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return -1;
  }
}

void main() {
  int[] array = {2, 4, 15, 16, 70, 81, 99};
  for (int i : array) System.out.print(i + " ");
  System.out.println();

  Scanner input = new Scanner(System.in);

  System.out.print("Enter the element to be searched: ");

  int element = input.nextInt();
  input.close();

  int index;
  if ((index = Solution.binarySearch(array, element)) != -1) {
    System.out.println("Element found at index: " + index);
  } else {
    System.out.println("Element not found.");
  }
}
