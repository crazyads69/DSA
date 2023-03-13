# Cấu trúc dữ liệu và giải thuật - Buổi 02
# Trình bày bởi: Lê Minh Trí và Nguyễn Phúc Thịnh
1. **Sắp xếp chèn (Insertion Sort)**
- Thuật toán sắp xếp chèn **thực hiện sắp xếp dãy số theo cách duyệt từng phần tử và chèn từng phần tử đó vào đúng vị trí trong mảng con (dãy số từ đầu đến phần tử phía trước nó)** đã sắp xếp sao cho dãy số trong mảng sắp đã xếp đó vẫn đảm bảo tính chất của một dãy số tăng dần.
- **Đánh giá:**
    - Độ phức tạp trong trường hợp xấu nhất là **O(n^2)** khi phải duyệt hết toàn bộ mảng.
    - Độ phức tạp trung bình là **O(n^2)**.
    - Độ phức tạp trong trường hợp tốt nhất là **O(n)** khi mảng đã có sẵn thứ tự tăng dần.
- **Ưu điểm:**
    - Dễ dàng cài đặt, giải thuật đơn giản dễ hiểu, phù hợp cho việc học tập và nghiên cứu.
    - Thuật toán có tính ổn định.
    - Hoạt động tốt nếu mảng cần sắp xếp nhỏ và đã được sắp xếp một phần.
    - Tốn ít bộ nhớ.
- **Nhược điểm:**
    - Là thuật toán có độ phức tạp lớn **O(n^2)** chính vì thế không thể áp dụng với dữ liệu lớn.
    - Hiệu suất của thuật toán thấp, không thực sự tối ưu.
- **Ý tưởng:**
    - **Input:** Mảng A gồm n phần tử chưa có thứ tự
    - **Output:** Mảng A gồm n phần tử được sắp xếp theo thứ tự tăng dần.
    - **Mô phỏng:**
        -   Khởi tạo mảng với dãy con đã sắp xếp có **k = 1** phần tử **(phần tử đầu tiên, phần tử có chỉ số 0)**.
        - Duyệt từng phần tử từ phần tử thứ 2, tại mỗi lần duyệt phần tử ở chỉ số i thì đặt phần tử đó vào một vị trí nào đó trong đoạn từ **[0…i]** sao cho dãy số từ **[0…i]** vẫn đảm bảo tính chất dãy số tăng dần. Sau mỗi lần duyệt, số phần tử đã được sắp xếp **k** trong mảng tăng thêm 1 phần tử.
        - Lặp cho tới khi duyệt hết tất cả các phần tử của mảng.

![Minh hoạ cho thuật toán sắp xếp chèn](https://i.imgur.com/dM2RhCB.gif)


- **Cài đặt thuật toán sắp xếp chèn:**

```cpp=
void InsertionSort(int a[], int n)
{
    int current, k;
    for (int i = 1; i < n; i++)
    {
        current = a[i];
        for (k = i - 1; k >= 0; k--)
        {
            if (a[k] < current)
                break;
            a[k + 1] = a[k];
        }
        a[k + 1] = current;
    }
}
```
 
2. **Sắp xếp gộp (Merge Sort)**
- Sắp xếp trộn là một thuật toán sắp xếp dựa trên giải thuật **Divide and Conquer (Chia để trị)**.
- Thuật toán này sẽ **chia mảng thành hai nữa rồi sắp xếp trên từng nữa một**. Sau đó **kết hợp chúng lại với nhau thành một mảng đã được sắp xếp**.
- **Đánh giá:**
    - Độ phức tạp trong trường hợp xấu nhất là **O(nlog(n))**.
    - Độ phức tạp trung bình là **O(nlog(n))**.
- **Ưu điểm:**
    - Độ phức tạp trung bình **O(nlog(n))**, tốc độ giải quyết khá nhanh.
    - Có tính ổn định và thích ứng, tốc độ không bị ảnh hưởng nhiều bởi dữ liệu đầu vào.
    - Xử lý khá tốt với dữ liệu lớn đặc biệt là dạng list, file.
- **Nhược điểm:**
    - Tốn nhiều bộ nhớ nếu sử dụng đệ quy.
    - Code khó cài đặt, tương đối phức tạp.
    - Trong hầu hết các trường hợp, thuật toán này không được đánh giá cao hơn Quick sort.
- **Ý tưởng:**
    - **Input:** Mảng A gồm n phần tử chưa được sắp xếp.
    - **Output:** Mảng A gồm n phần tử được sắp xếp theo thứ tự tăng dần.
    - **Mô phỏng:**
        - **Chia (Divide):** Chia mảng gồm **n** phần tử cần sắp xếp thành 2 mảng, mỗi mảng có **n/2** phần tử.
        - **Trị (Conquer):** Sắp xếp mỗi mảng con một cách đệ quy sử dụng sắp xếp trộn. Khi dãy chỉ còn một phần tử thì trả lại phần tử này.
        - **Tổ hợp (Combine): Trộn (Merge)** hai mảng con được sắp xếp để thu được mảng được sắp xếp gồm tất cả các phần tử của cả hai mảng con.

![Minh hoạ thuật toán sắp xếp trộn - Merge Sort](https://i.imgur.com/aCi3gse.gif)

        
- **Cài đặt thuật toán sắp xếp trộn:**

```cpp=
void Merge(int a[], int mid, int left, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // tạo 2 mảng tạm thời để chứa các phần tử sau khi chia
    int L[n1], R[n2];
    // Copy dữ liệu từ mảng chính sang mảng tạm
    for (i = 0; i < n1; i++)
    {
        L[i] = a[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = a[mid + 1 + j];
    }
    i = 0;    // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0;    // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = left; // Khởi tạo chỉ số bắt đầu của mảng lưu kết quả
              
    // Trộn hai mảng tạm vừa rồi vào mảng a
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    // Lấy phần còn lại của dãy L cho vào cuối mảng a nếu còn.
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    // Lấy phần còn lại của dãy R cho vào cuối mảng a nếu còn.
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        // Tìm chỉ số nằm giữa mảng để chia mảng thành 2 nửa:
        int mid = left + (right - left) / 2;
        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        // Gọi hàm trộn
        Merge(a, mid, left, right);
    }
}
```

## **Xem thêm:**
- [Thuật toán sắp xếp chèn - Insertion Sort - Ông Dev](https://youtu.be/IWT-Uoz_Sb8)
- [Thuật toán sắp xếp trộn - Merge Sort P.1 - Ông Dev](https://youtu.be/f2nTwlZiuMI)
- [Thuật toán sắp xếp trộn - Merge Sort P.2 - Ông Dev](https://youtu.be/Pq5y-MzBdWs)