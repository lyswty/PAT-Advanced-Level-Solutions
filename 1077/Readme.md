注意cin虽然遇到换行会停止，但是换行符并不接收到输入流中，因此cin之后如果要用getline的话，需要用getchar（）把换行过滤掉。sstream也是同理