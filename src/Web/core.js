//window.alert("Welcome to Project: Sol");
//
var listSite = [   
    
    "https://kissanime.to/"     ,   
    "http://www.anime4fun.ro/"  ,
    "http://playtech.ro/"       ,
    "https://wow.freakz.ro/"    ,
    "http://www.lovendal.ro/wp52/"
]


var index = 0;
    
function commandPage(command)
{

    switch(command)
    {
        case "next":
        
            if( index < listSite.length - 1)
                index = index + 1;
            else
                index = 0;
                
            console.log(index);
            document.getElementById("frame").src = listSite[index];
            
                    break;
                
        case "previous":
        
            if(index == 0)
                index = listSite.length - 1;
            else
                index = index - 1;
                
            console.log(index);
            document.getElementById("frame").src = listSite[index];
            
                break;
                
        case "list":
         
             window.alert(listSite);
            
                    break;
        default:
        
              window.alert("Unknown command");
                    break;
    }
    
}



