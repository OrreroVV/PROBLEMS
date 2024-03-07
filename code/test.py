import pandas as pd

# 创建一个包含数据行的列表
data_row = [[3, 5, 10, 3]]

# 指定要写入的 Excel 文件路径
excel_file = "example_data_row.xlsx"

# 创建一个空的 DataFrame
df = pd.DataFrame()

# 逐行插入数据行
for row in data_row:
    df = df.append(pd.Series(row), ignore_index=True)

# 写入 DataFrame 到 Excel 文件
df.to_excel(excel_file, index=False)

print("数据行写入 Excel 文件成功！")