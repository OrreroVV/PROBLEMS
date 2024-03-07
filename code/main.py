import pandas as pd
from collections import defaultdict
import numpy
import math

def work():
    # 指定 Excel 文件路径
    excel_file = "D:\\Code\\C++\\vscode\\data\\2011-2022上市公司碳排放数据.xlsx"

    # 使用 read_excel 函数读取 Excel 文件
    df = pd.read_excel(excel_file, sheet_name='Sheet2')



    # 获取数据框的行数（索引从0开始）
    num_rows = len(df)
    cnt = {}
    res = {}
    # 获取第一行的列名称
    column_names = df.columns
    
    st = {}

    for i in column_names[5:15]:
        st[i] = True

    for index, row in df.iterrows():
        year = df.iloc[index, 2]
        idx = df.iloc[index, 0]
        if pd.isna(idx):
            continue

        idx = int(idx)
        year = int(year)
        month = df.iloc[index, 3]
        if  pd.isna(month):
            continue
        month = int(month)
        if not 1 <= month <= 12:
            continue


        if idx not in cnt:
            cnt[idx] = {}

        if year not in cnt[idx]:
            cnt[idx][year] = 0
        
        cnt[idx][year] += 1
        for column_name, value in row.items():
            if column_name not in st:
                continue
            

            if idx not in res:
                res[idx] = {}

            if year not in res[idx]:
                res[idx][year] = {}
            
            if column_name not in res[idx][year]:
                res[idx][year][column_name] = value
            else:
                res[idx][year][column_name] += value

   
    # print(res)
    import xlwt
    # 创建新的workbook（其实就是创建新的excel）
    workbook = xlwt.Workbook(encoding= 'ascii')
 
    # 创建新的sheet表
    worksheet = workbook.add_sheet("Sheet1")

    
    row = 0

    worksheet.write(row, 0, "证券代码")
    worksheet.write(row, 1, "年")
    worksheet.write(row, 2, "上市公司碳排放总量（吨）")
    worksheet.write(row, 3, "化石燃料燃烧排放")
    worksheet.write(row, 4, "生物质燃料燃烧排放")
    worksheet.write(row, 5, "原料开采逃逸排放")
    worksheet.write(row, 6, "石油和天然气系统逃逸排放")
    worksheet.write(row, 7, "电力调入调出间接碳排放")
    worksheet.write(row, 8, "生产过程排放")
    worksheet.write(row, 9, "固体废弃物焚烧排放")
    worksheet.write(row, 10, "污水处理导致的排放")
    worksheet.write(row, 11, "土地利用方式转变（森林转为工业用地）导致的排放")
    row += 1
    for val in res:
        val = int(val)
        
        # print(val, year)
        for year in res[val]:
            
            worksheet.write(row, 0, val)
            worksheet.write(row, 1, year)
            if cnt[val][year] != 4:    
                col = 2
                for name in res[val][year]:
                    worksheet.write(row, col, 0)
                    col += 1
                row += 1
            else:
                col = 2
                for name in res[val][year]:
                    worksheet.write(row, col, res[val][year][name])
                    col += 1
                row += 1
    

    # 保存
    workbook.save("output.xls")




if __name__ == "__main__":
    work()