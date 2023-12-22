void read()
{
char str[20];
gets(str);
printf("%s", str);
return;
}
//Mã trông đơn giản, nó đọc chuỗi từ đầu vào tiêu chuẩn và in chuỗi đã nhập, nhưng nó bị Tràn bộ đệm vì gets() không thực hiện bất kỳ thử nghiệm giới hạn mảng nào.
//gets() tiếp tục đọc cho đến khi nhìn thấy ký tự dòng mới. 
