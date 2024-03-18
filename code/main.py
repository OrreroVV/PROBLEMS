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
    rate = {}
    suml = {}
    sumr = {}
    # 获取第一行的列名称
    column_names = df.columns
    
    st = {}

    for i in column_names[5:15]:
        st[i] = True

    for index, row in df.iterrows():
        year = df.iloc[index, 2]
        idx = df.iloc[index, 0]
        position = df.iloc[index, 4]
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
            if value == 0:
                cnt[idx][year] = 0
            
            if idx not in res:
                res[idx] = {}
            if idx not in rate:
                rate[idx] = {}
            if idx not in suml:
                suml[idx] = {}
            if idx not in sumr:
                sumr[idx] = {}
            

            if year not in res[idx]:
                res[idx][year] = {}
            if year not in rate[idx]:
                rate[idx][year] = {}
                
            if year not in suml[idx]:
                suml[idx][year] = {}
            if year not in sumr[idx]:
                sumr[idx][year] = {}
            


            if "position" not in res[idx][year]:
                res[idx][year]["position"] = position
            
            rate[idx][year][column_name] = "INF"
            
            if column_name not in suml[idx][year]:
                suml[idx][year][column_name] = []
                suml[idx][year][column_name].append(0)
            
            suml[idx][year][column_name].append(0)
            if column_name not in sumr[idx][year]:
                sumr[idx][year][column_name] = []
                sumr[idx][year][column_name].append(0)
                
            sumr[idx][year][column_name].append(0)

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
    


    for val in res:
        val = int(val)
        for year in res[val]:
            if year == 2022:
                continue
            
            last = -1
            if cnt[val][year] == 4:    
                for name in res[val][year]:
                    if name == 'position':
                        continue

                    if last == -1:
                        last = res[val][year][name]
                        continue

                    if last != 0:
                        rate[val][year][name] = (res[val][year][name] - last) / last; 

                    # print(val, year, res[val][year]['position'], rate[val][year][name])
                    last = res[val][year][name]
            else:
                for name in res[val][year]:
                    if name == 'position':
                        continue
                    res[val][year][name] = 0


    for val in res:
        val = int(val)
        for year in res[val]:
            if year == 2022:
                continue
            
            if cnt[val][year] != 4:    
                for name in res[val][year]:
                    if name == 'position':
                        continue
                    
                    numl = 0
                    for i in range(1, 5):
                        if year - i in rate[val] and res[val][year - i][name] != 0:
                            numl = -i
                        else:
                            break
                    if numl >= 2:
                        avg = 0
                        for i in range(1, numl):
                            avg += (res[val][year - i][name] - res[val][year - i - 1][name]) / res[val][year - i - 1][name]
                        
                        avg /= numl - 1
                        res[val][year][name] = (1 + avg) * res[val][year - 1][name]
                        if val == 900956 and year == 2020:
                            print(val, year, name, res[val][year][name])

    for val in res:
        val = int(val)
        for year in range(2000, 2021, -1):
            
            if year not in res[val]:
                continue

            if cnt[val][year] != 4:    
                for name in res[val][year]:
                    if res[val][year][name] != 0:
                        continue
                    if name == 'position':
                        continue
                    
                    numr = 0
                    for i in range(1, 5):
                        if year + i in rate[val] and res[val][year + i][name] != 0:
                            numr = i
                        else:
                            break
                    if numr >= 2:
                        avg = 0
                        # year + i, year + i + 1
                        for i in range(1, numr):
                            avg += (res[val][year + i][name] - res[val][year + i + 1][name]) / res[val][year + i + 1][name]
                        
                        avg /= numr - 1
                        res[val][year][name] = (1 - avg) * res[val][year + 1][name]
                        # print(val, year, name, avg, res[val][year][name])



    row = 0
    colList = []
    colList.append("证券代码")
    colList.append("年")
    colList.append("行业")
    colList.append("上市公司碳排放总量（吨）")
    colList.append("化石燃料燃烧排放")
    colList.append("生物质燃料燃烧排放")
    colList.append("原料开采逃逸排放")
    colList.append("石油和天然气系统逃逸排放")
    colList.append("电力调入调出间接碳排放")
    colList.append("生产过程排放")
    colList.append("固体废弃物焚烧排放")
    colList.append("污水处理导致的排放")
    colList.append("土地利用方式转变（森林转为工业用地）导致的排放")

    col = 0
    for value in colList:
        worksheet.write(0, col, value)
        col += 1

    row += 1
    for val in res:
        val = int(val)
        
        # print(val, year)
        for year in res[val]:
            
            if year == 2022:
                continue
            
            worksheet.write(row, 0, val)
            worksheet.write(row, 1, year)
            worksheet.write(row, 2, res[val][year]['position'])
            col = 3
            for name in res[val][year]:
                if name == 'position':
                    continue
                worksheet.write(row, col, res[val][year][name])
                col += 1
            row += 1

    

    # 保存
    workbook.save("output/output.xls")




if __name__ == "__main__":
    work()