from numpy import *
import matplotlib
matplotlib.rcParams['savefig.dpi']=600
import matplotlib.pyplot as plt
import sys
import matplotlib2tikz
import PIL
import socket
import os
import os.path
import datetime
import traceback
import subprocess

try:
    import git
    def get_git_metadata():
        repo = git.Repo(search_parent_directories=True)
        sha = repo.head.object.hexsha
        modified= repo.is_dirty()
        activeBranch = repo.active_branch
        url = repo.remotes.origin.url
        
        return {'git_commit': str(sha), 
                'git_repo_modified':str(modified),
                'git_branch' : str(activeBranch),
                'git_remote_url' : str(url)}
        
    
    def add_git_information(filename):
        writeMetadata(filename, get_git_metadata())
        
except:
    def add_git_information(filename):
        pass
    
    def get_git_metadata():
        return {'git_commit': 'unknown', 
                'git_repo_modified':'unknown',
                'git_branch' : 'unknown',
                'git_remote_url' : 'unknown'}



def writeMetadata(filename, data):
    im = PIL.Image.open(filename)
    
    meta = PIL.PngImagePlugin.PngInfo()

    for key in data.keys():
        meta.add_text(key, str(data[key]))
    im.save(filename, "png", pnginfo=meta)
    
def savePlot(name):
    name = showAndSave.prefix + name
    name = ''.join(ch for ch in name if ch.isalnum() or ch =='_')
    
    
    fig = plt.gcf()
    ax = plt.gca()
    gitMetadata = get_git_metadata()
    informationText = 'By Kjetil Lye@ETHZ <kjetil.o.lye@gmail.com>\nCommit: %s\nRepo: %s\nHostname: %s' % (gitMetadata['git_commit'], gitMetadata['git_remote_url'], socket.gethostname())
    
    ax.text(0.95, 0.01, informationText,
         fontsize=3, color='gray',
         ha='right', va='bottom', alpha=0.5, transform=ax.transAxes)

    matplotlib2tikz.save(name + '.tikz',
           figureheight = '\\figureheight',
           figurewidth = '\\figurewidth',
           show_info = False)
    
    savenamepng = name + '.png'
    plt.savefig(savenamepng, bbox_inches='tight')
    
    writeMetadata(savenamepng, {'Copyright' : 'Copyright Kjetil Lye@ETHZ <kjetil.o.lye@gmail.com>'
                               })
    
    add_git_information(savenamepng)
    writeMetadata(savenamepng, {'working_directory': os.getcwd(), 
                                'hostname':socket.gethostname(),
                                'generated_on_date': str(datetime.datetime.now())})
def showAndSave(name):
    savePlot(name)
    plt.show()
    
showAndSave.prefix=''
    
    
def legendLeft():
    ax = plt.gca()
    ax.legend(loc='center left', bbox_to_anchor=(1, 0.5))
    
def console_log(x):
    """Simple hack to write to stdout from a notebook"""
    
    x=str(x)
    with open('/dev/stdout', 'w') as f:
        f.write("\n\n\n------------DEBUG OUTPUT------------\n")
        f.write("%s\n"%x)
        f.write('------------DEBUG OUTPUT------------\n\n')
        f.flush()


if __name__ == '__main__':
    labels=['o', '*', 'x']
    N = int(sys.argv[1])

    for (n, method) in enumerate(sys.argv[2:-1]):
        if method=='monte_carlo':
            points = random.uniform(0,1,(N,2))
        else:
            print(method)
            result = subprocess.run(['./dryrun/dryrun',  method, '2', str(N)], stdout=subprocess.PIPE)

            data = result.stdout
            splitted = data.split()
    
            numberOfPoints = int(splitted[0])

            points = []

            print(len(splitted))
            print(numberOfPoints)

            for i in range(N):
                points.append([])
                for j in range(2):
                    points[i].append(float(splitted[i*2+j+1]))

            points = array(points)
        plt.plot(points[:,0], points[:,1], labels[n], label=method.replace('_', ' ').title())
        plt.xlabel('$x$')
        plt.grid('on')
        plt.ylabel('$y$')
        plt.title('Distribution of integration points')
    legendLeft()
    showAndSave(sys.argv[-1])
    
    
