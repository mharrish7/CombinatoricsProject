from flask import Flask,render_template,jsonify,request
import subprocess
from subprocess import PIPE

app = Flask(__name__)



@app.route("/")
def home():
    return render_template('index.html')

@app.route("/data" , methods = ['POST'])
def data():
    dat = request.form.getlist('info[]')
    adj = {}
    for i in range(0,len(dat),2):
        if dat[i] not in adj:
            adj[dat[i]] = [dat[i+1]]
        else:
            adj[dat[i]].append(dat[i+1])
        
        if dat[i+1] not in adj:
            adj[dat[i+1]] = [dat[i]]
        else:
            adj[dat[i+1]].append(dat[i])
    
    n = len(adj)

    m = int(sorted(dat)[-1][1])
    adj1 = [ [0 for i in range(m)] for j in range(m)]
    print(adj1)
    print(adj)
    for i in range(1,m+1):
        for j in range(1,m+1):
            if "d" + str(i) in adj and "d" + str(j) in adj["d" + str(i)]:
                adj1[i-1][j-1] = 1

    print(adj1)

    inp = str(m) + "\n"
    for i in adj1:
        inp += " ".join(map(str,i)) + '\n'

    print(inp)
    sr=subprocess.run("color.exe",input = inp.encode(),stdout=PIPE,shell=True)

    dirlist=sr.stdout.decode("utf-8")
    print(dirlist)
    t1 = dirlist.split('\n')
    L = []
    for i in t1[1:]:
        if i!= '':
            L.append(int(i[0]))
    print(L)
    return jsonify({'data' : L})

app.run(debug=True)