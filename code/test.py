import pandas as pd

# 指定 dta 文件路径
dta_file = "data/GTA2021final.dta"
# 使用 read_stata() 函数读取 dta 文件
#导入pandas包
import pandas as pd
#读取dta文件
data = pd.io.stata.read_stata(dta_file)
#写入csv，并且转码。
#如果不转码的话，中文会出现乱码的情况。看过很多教程都是转的utf-8，但是我试过还是会乱码。换成ansi就好了。
data.to_csv(dta_file,)
