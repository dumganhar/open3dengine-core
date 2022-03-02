## 构建方法

### Mac

```bash
# 打开终端，执行以下命令生成工程
cd open3dengine-core
mkdir build
cmake .. -GXcode -DLY_3RDPARTY_PATH=<3rdParty package path>
# <3rdParty package path> 为 AZCore 依赖的第三库的绝对路径，可以指定一个本地空文件夹的绝对路径
open O3DE.xcodeproj # 打开工程
# 执行 ALL_BUILD 编译任务
# 设置 AzTestRunner 为启动工程
# 设置 AzTestRunner 的 Scheme，在 Arguments 中新增 AzCore.Tests 和 AzRunUnitTests
# 直接运行工程，会跑每个 AzCore 的测试例
```

### Windows

```bash
# 打开 cmd
cd open3dengine-core

```

