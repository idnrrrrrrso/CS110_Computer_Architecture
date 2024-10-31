张语晴

1. writing on those callee saved register (values should be unchanged before and after a function call) without saving their values

2. NO. They are not function calls.

3. 因为 `mul_arr` 里有函数嵌套，又调用了 `helper_fun`。如果不存一下，`mul_arr` 想要返回的地址会被 `helper_fun` overwrite.

4. 我猜是因为函数嵌套？Venus以为我在外层函数里已经存过了。但实际上，调用内层的时候应该再存一遍。