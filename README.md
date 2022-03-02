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
md build
cd build
# 确保已经安装好 VS2019
cmake .. -G "Visual Studio 16" -DLY_3RDPARTY_PATH=<3rdParty package path>
# <3rdParty package path> 为 AZCore 依赖的第三库的绝对路径，可以指定一个本地空文件夹的绝对路径
# 双击 build/O3DE.sln，用 VS2019 打开
# 在 Solution Explorer 窗口中右键单击 Solution 'O3DE'，选择 Build Solution 进行编译整个项目
# 在 Solution Explorer 窗口中，设置 Code/Tools/AzTestRunner 为启动项目（右键 AzTestRunner 工程，Set as Startup Project）
# 右键 AzTestRunner 工程，点击 Property（属性），在 Debugging （调试）窗口中，设置 Command Arguments 为 AzCore.Tests AzRunUnitTests，设置 Working Directory 为 $(OutputPath)
# 运行工程，在 cmd 中会输出每个 UnitTests 的结果
```

