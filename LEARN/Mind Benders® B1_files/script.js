/* Listak LLC Business Intelligence (c)  */
/* Build Date 11/22/2013 12:05:36 PM */
/* Version v1 - Thu, 03 Oct 2013 14:01:00 GMT */

var _protocol = ("https:" == document.location.protocol) ? "https://" : "http://";



(function() {
	if (!window.jQuery) {
		var jq = document.createElement('script');
		jq.src = _protocol + 'ajax.googleapis.com/ajax/libs/jquery/1.4.2/jquery.min.js';
		jq.onload = jq.onreadystatechange = function() { if(window.jQuery && typeof (jq) !== 'undefined' && (!jq.readyState || /loaded|complete/.test(jq.readyState))) { jQuery.noConflict(); jq.onload = jq.readystatechange = null; jq=undefined; } };
		document.documentElement.children[0].appendChild(jq);
	}
})();


LTK.prototype.cookie=function(key,value,options){return"";};LTK.prototype.cookiesEnabled=function(){var _dt=new Date();_dt.setSeconds(_dt.getSeconds()+180);var _enabled=(this.cookie("checkCookies","enabled",{expires:_dt,path:"/"})&&this.cookie("checkCookies")=="enabled");if(_enabled)
this.cookie("checkCookies","deleted",{expires:new Date(1970,1,1,0,0,0),path:"/"});return _enabled;};var _ltgsi=setInterval(function(){if(!window.jQuery){return;}
clearInterval(_ltgsi);;(function(factory){if(typeof define==='function'&&define.amd){define(['jquery'],factory);}else{factory(jQuery);}}
(function($){LTK.prototype.cookie=function(key,value,options){if(arguments.length>1&&String(value)!=="[object Object]"){options=jQuery.extend({},options);if(value===null||value===undefined){options.expires=-1;}
if(typeof options.expires==='number'){var days=options.expires,t=options.expires=new Date();t.setDate(t.getDate()+days);}
value=String(value);return(document.cookie=[encodeURIComponent(key),'=',options.raw?value:encodeURIComponent(value),options.expires?'; expires='+options.expires.toUTCString():'',options.path?'; path='+options.path:'',options.domain?'; domain='+options.domain:'',options.secure?'; secure':''].join(''));}
options=value||{};var result,decode=options.raw?function(s){return s;}:decodeURIComponent;return(result=new RegExp('(?:^|; )'+encodeURIComponent(key)+'=([^;]*)').exec(document.cookie))?decode(result[1]):null;};}));},100);LTK.prototype.urlParam=function(name){name=name.replace(/[\[]/,"\\\[").replace(/[\]]/,"\\\]");var regexS="[\\?&]"+name+"=([^&#]*)";var regex=new RegExp(regexS);var results=regex.exec(window.location.href);if(results==null)
return"";else
return results[1];}
LTK.prototype.isValidEmail=function(email){var watermarkFilter=new Array();var isWatermark=false;var emailFilter=/^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;watermarkFilter=["user@example.com","email@example.com","customer@example.com","user@domain.com","email@domain.com","customer@domain.com"];for(var i=0;i<watermarkFilter.length;i++){if(watermarkFilter[i]===email)
isWatermark=true;}
if(!emailFilter.test(email)||isWatermark)
return false;else
return true;};if(!LTK.prototype.browser){ua=navigator.userAgent.toLowerCase();var match=/(chrome)[ \/]([\w.]+)/.exec(ua)||/(webkit)[ \/]([\w.]+)/.exec(ua)||/(opera)(?:.*version|)[ \/]([\w.]+)/.exec(ua)||/(msie) ([\w.]+)/.exec(ua)||ua.indexOf("compatible")<0&&/(mozilla)(?:.*? rv:([\w.]+)|)/.exec(ua)||[];matched={browser:match[1]||"",version:match[2]||"0"};browser={};if(matched.browser){browser[matched.browser]=true;browser.version=matched.version;}
if(browser.chrome){browser.webkit=true;}else if(browser.webkit){browser.safari=true;}
LTK.prototype.browser=browser;if(typeof _ltk!='undefined')
_ltk.browser=browser;}


function AsyncManager(){this.Calls=[];AsyncManager.prototype.StartAsyncCall=function(callName,delegate,callsToWaitFor,timeoutInMilliseconds){try{var call=new AsyncCall(callName,delegate,callsToWaitFor,this);this.Calls.push(call);if(delegate===undefined){call.InProgress=true;}else{if(timeoutInMilliseconds!==undefined){var startTimeout=function(call){setTimeout(function(){if(!call.InProgress){call.InProgress=true;call.Delegate();call.Complete();}},timeoutInMilliseconds);};startTimeout(call);}
this.CheckWait(call);}
return call;}
catch(ex){_ltk.Exception.Submit(ex,'AsyncManager.StartAsyncCall');return null;}};AsyncManager.prototype.CallComplete=function(callName){try{for(var c=0;c<this.Calls.length;c++){if(this.Calls[c].Name==callName){this.Calls.splice(c,1);break;}}
if(document.dispatchEvent){var customEvent=document.createEvent('Event');customEvent.initEvent('AsyncCallComplete',false,false);document.dispatchEvent(customEvent);}else if(document.fireEvent){document.documentElement.ltkAsyncCallComplete+=1;}}
catch(ex){_ltk.Exception.Submit(ex,'AsyncManager.CallComplete');return null;}};AsyncManager.prototype.IsCallQueued=function(callName){for(var c=0;c<this.Calls.length;c++){if(this.Calls[c].Name==callName){return true;}}
return false;};AsyncManager.prototype.CheckWait=function(call){if(call.InProgress){return;}
var keepWaiting=false;for(var n=0;n<call.CallsToWaitFor.length;n++){if(this.IsCallQueued(call.CallsToWaitFor[n])){keepWaiting=true;break;}}
if(!keepWaiting){call.InProgress=true;var execute=function(call){setTimeout(function(){call.Delegate();call.Complete();},0);};execute(call);}};AsyncManager.prototype.CheckAllWaits=function(){for(var c=0;c<this.Calls.length;c++){this.CheckWait(this.Calls[c]);}};if(document.addEventListener){document.addEventListener('AsyncCallComplete',AsyncManager.CallCompleteHandler);}else if(document.attachEvent){document.documentElement.ltkAsyncCallComplete=0;document.documentElement.attachEvent("onpropertychange",function(event){if(event.propertyName=="ltkAsyncCallComplete"){AsyncManager.CallCompleteHandler();}});}}
AsyncManager.CallCompleteHandler=function(){_ltk.AsyncManager.CheckAllWaits();};function AsyncCall(callName,delegate,callsToWaitFor,manager){this.Name=callName;this.Delegate=delegate;this.CallsToWaitFor=callsToWaitFor;this.InProgress=false;AsyncCall.prototype.Complete=function(){manager.CallComplete(this.Name);};}


LTK.prototype.moduleList = ['PCO', 'SCA', 'PPE', 'LCG'];


function LTK(){this.SCA=new SessionTracker();this.Order=new _Order();this.Items=new Array();this.Products=new Array();this.Customer=new _Customer();this.Client=new _Client();this.TRKT=new _TRKT();this.Subscriber=new _LTKSubscriber();this.Assembler=new _Assembler();this.Click=new _LTKClick();this.Exception=new _LTKException();this.TransactionIDs=new Array();this.Activity=new _ActivityList();this.Alerts=new _Alerts();this.AsyncManager=new AsyncManager();LTK.prototype.Submit=function(){try{this.TRKT.T=this.GetCookie("_trkt");this.TRKT.Event='t';this.Order.SetSessionID();this.PostData();}
catch(ex){this.Exception.Submit(ex,'Submit and Post Data');}}
LTK.prototype.PostData=function(uid){this.Assembler.QueryHeader="ctid="+this.Client.CTID+(this.Client.DebugMode?"&debugmode=true":"")+"&uid="+this.uuidCompact();this.Assembler.AddObject(this.Order);this.Assembler.AddObject(this.TRKT);this.Assembler.AddObject(this.Customer);this.Assembler.AddArrayObject(this.Items);this.Assembler.AddArrayObject(this.Products);this.Assembler.Flush();}
LTK.prototype.RandomString=function(length){var text="";var possible="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";for(var i=0;i<length;i++)
text+=possible.charAt(Math.floor(Math.random()*possible.length));return text;}
LTK.prototype.uuidCompact=function(){var id=this.generateUUID();try{this.TransactionIDs.push(id);}
catch(ex){}
return id;};LTK.prototype.generateUUID=function(){var id='xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g,function(c){var r=Math.random()*16|0,v=c=='x'?r:(r&0x3|0x8);return v.toString(16);}).toUpperCase();return id;};LTK.prototype.GetCookie=function(sName){var sRE="(?:; )?"+sName+"=([^;]*);?";var oRE=new RegExp(sRE);if(oRE.test(document.cookie)){return decodeURIComponent(RegExp["$1"]);}else{return null;}}}
function _Order(){this._type='o';this.UID=null;this.OrderNumber=null;this.OrderTotal=null;this.TaxTotal=null;this.ShippingTotal=null;this.HandlingTotal=null;this.ItemTotal=null;this.Currency=null;this.Meta1=null;this.Meta2=null;this.Meta3=null;this.Meta4=null;this.Meta5=null;this.SessionID=null;this.Source=null;this._varmap={'_type':'_t','UID':'uid','OrderNumber':'on','OrderTotal':'ot','TaxTotal':'tt','ShippingTotal':'st','HandlingTotal':'ht','ItemTotal':'it','Currency':'c','Meta1':'m1','Meta2':'m2','Meta3':'m3','Meta4':'m4','Meta5':'m5','SessionID':'s','Source':'sr'};_Order.prototype.SetSessionID=function(){try{if(this.OrderNumber!=null)
this.SessionID=_ltk.SCA.sessionID;}
catch(ex){_ltk.Exception.Submit(ex,'OrderSetSession');}}
_Order.prototype.SetCustomer=function(email,firstname,lastname){_ltk.Customer.Email=email;_ltk.Customer.FirstName=firstname;_ltk.Customer.LastName=lastname;}
_Order.prototype.Submit=function(){_ltk.Submit();}
_Order.prototype.AddItem=function(id,quantity,price){try{var _item=new this.Item(id,quantity,price);_ltk.Items.push(_item);}
catch(ex){_ltk.Exception.Submit(ex,'Add Item');}}
_Order.prototype.AddItemEx=function(item){try{_ltk.Items.push(item);}
catch(ex){_ltk.Exception.Submit(ex,'Add Item Ex');}}
_Order.prototype.Item=function(id,quantity,price){this._type='i';this.UID=null;this.ID=id;this.Name=null;this.Quantity=quantity;this.Price=price;this.RowID=null;this.Meta1=null;this.Meta2=null;this.Meta3=null;this.Meta4=null;this.Meta5=null;this._varmap={'_type':'_t','UID':'uid','ID':'id','Name':'n','Quantity':'q','Price':'p','RowID':'ri','Meta1':'m1','Meta2':'m2','Meta3':'m3','Meta4':'m4','Meta5':'m5'};}}
function _TRKT(){this._type='tt';this.UID=null;this.T=null;this.Event=null;this._varmap={'_type':'_t','UID':'uid','T':'t','Event':'e'};}
function _Product(id,_name,price,imageUrl,itemUrl,description,masterSku,reviewProductID){this._type='p';this.UID=null;this.ID=id;this.Name=_name;this.Price=price;this.ImageUrl=imageUrl;this.ItemUrl=itemUrl;this.Description=description;this.Meta1=null;this.Meta2=null;this.Meta3=null;this.Meta4=null;this.Meta5=null;this.MasterSku=typeof masterSku=="undefined"?null:masterSku;this.ReviewProductID=typeof reviewProductID=="undefined"?null:reviewProductID;this.Discontinued=null;this._varmap={'_type':'_t','UID':'uid','ID':'id','Name':'n','Price':'p','ImageUrl':'imu','ItemUrl':'itu','Description':'d','Meta1':'m1','Meta2':'m2','Meta3':'m3','Meta4':'m4','Meta5':'m5','MasterSku':'ms','ReviewProductID':'rpi','Discontinued':'ds'};_Product.prototype.Add=function(){try{_ltk.Products.push(this);}
catch(ex){_ltk.Exception.Submit(ex,'Add Product');}}}
function _Customer(){this._type='c';this.UID=null;this.Email=null;this.FirstName=null;this.LastName=null;this.Meta1=null;this.Meta2=null;this.Meta3=null;this.Meta4=null;this.Meta5=null;this._varmap={'_type':'_t','UID':'uid','Email':'e','FirstName':'fn','LastName':'ln','Meta1':'m1','Meta2':'m2','Meta3':'m3','Meta4':'m4','Meta5':'m5'};}
function _Client(){this.CTID=null;this.DebugMode=false;}
function _Assembler(){this.QueryHeader=null;this.QueryMode=0;this.EndPointArray=['s1.listrakbi.com/t','s2.listrakbi.com/t'];this.EndPointPath='/T.ashx';this.EndPointIndex=0;this.EnumIndex=0;this.MaxLength=950;this.Query='';this._protocol=(("https:"==document.location.protocol)?"https://":"http://");_Assembler.prototype.Reset=function(){this.Query='';if(this.QueryMode==0){this.EnumIndex=0;}}
_Assembler.prototype.Append=function(obj){var q=this.BuildQuery(obj);var tq=this.Query+q;if(tq.length>this.MaxLength){this.Flush();q=this.BuildQuery(obj);}
this.Query+=q;if(this.QueryMode==0||obj._isIndexable){this.EnumIndex++;}}
_Assembler.prototype.Flush=function(){if(this.Query!=''){var src=this._protocol+this.EndPointArray[this.EndPointIndex]+this.EndPointPath+'?'+this.QueryHeader+this.Query;var img=new Image();img.height=1;img.width=1;img.src=src;this.IncrementEndPointIndex();this.Reset();}}
_Assembler.prototype.IncrementEndPointIndex=function(){this.EndPointIndex++;if(this.EndPointIndex==this.EndPointArray.length)
this.EndPointIndex=0;}
_Assembler.prototype.BuildQuery=function(obj){var i=-1;var query='';for(var key in obj){if(key=="_varmap"||typeof obj[key]=='function')continue;i++;if(typeof obj[key]=='undefined'||obj[key]==null||typeof obj._varmap[key]=='undefined')continue;query+="&"+obj._varmap[key]+(this.QueryMode==0||obj._isIndexable?"_"+this.EnumIndex:"")+"="+encodeURIComponent(obj[key]);}
return query;}
_Assembler.prototype.AddObject=function(obj){if(typeof obj=='undefined'||obj==null||!this.HasValue(obj)||typeof(obj._varmap)=='undefined')return;this.Append(obj);}
_Assembler.prototype.AddArrayObject=function(obj){if(typeof obj=='undefined'||obj==null)return;for(var k in obj){this.AddObject(obj[k]);}}
_Assembler.prototype.HasValue=function(obj){if(typeof obj=='undefined'||obj==null)return false;if(typeof obj._varmap=='undefined'||obj._varmap==null)return false;var valueFound=false;for(var key in obj){if(key=="_varmap"||typeof obj[key]=='function'||key=='_type')continue;if(typeof obj[key]=='undefined'||obj[key]==null||typeof obj._varmap[key]=='undefined')continue;valueFound=true;}
return valueFound;}}
function _LTKException(){_LTKException.prototype.Submit=function(ex,info){var _endpoint='s1.listrakbi.com/t';var _protocol=(("https:"==document.location.protocol)?"https://":"http://");if(ex==null)return;var src=_protocol+_endpoint+'/EX.ashx?'+
((_ltk.Client.CTID==null)?'':'ctid='+_ltk.Client.CTID+'&')+'uid='+_ltk.uuidCompact()+'&'+'n='+encodeURIComponent(ex.name)+'&'+'m='+encodeURIComponent(ex.message)+'&'+
((info==null)?'':'i='+encodeURIComponent(info)+'&')+'h='+encodeURIComponent(document.location.href);var img=new Image();img.height=1;img.width=1;img.src=src;}}


function _LTKClick(){this._endpoint='s1.listrakbi.com/t';this._protocol=(("https:"==document.location.protocol)?"https://":"http://");this._rootHost=null;_LTKClick.prototype.SetCookie=function(n,v,e,d,p,s){var exd=new Date();exd.setDate(exd.getDate()+e);document.cookie=n+"="+encodeURIComponent(v)+
((e==null)?"":"; expires="+exd.toGMTString())+
((d==null&&d!="")?"":"; domain="+d)+
((p==null)?"":"; path="+p)+
((s)?"; secure":"");}
_LTKClick.prototype.Submit=function(){try{var hRES=/([\.]*[^\.]+\.(co\.uk|com|net|biz|org|co\.nz|info|jp|edu|mx|com\.br|es|ca|pro|co|au)$)|(^localhost$)/gi;var hRE=new RegExp(hRES);var trkRES=/[?&]*trk_[^=&]+=/gi;var trkRE=new RegExp(trkRES);var hostfound=true;var hREMatch=document.location.host.match(hRE);var trkREMatch=document.location.search.match(trkRE);if(hREMatch){this._roothost=hREMatch[0];if(this._roothost.indexOf(".")!=0)this._roothost="."+this._roothost;}else hostfound=false;if(hostfound&&trkREMatch){this.SetCookie("_trkt",'0',365,this._roothost,"/",null);this.ScriptPostData(this._protocol+this._endpoint+'/CT.ashx?'+((_ltk.Client.CTID==null)?'':'ctid='+_ltk.Client.CTID+'&')+((_ltk.Client.DebugMode)?'debugmode=true&':'')+'uid='+_ltk.uuidCompact()+'&_t_0=cp&e_0=c&q_0='+encodeURIComponent(document.location.search)+'&_version=1');}}
catch(ex){_ltk.Exception.Submit(ex,'Submit Click');}}
_LTKClick.prototype.ScriptPostData=function(url){var script=document.createElement("script");script.setAttribute("src",url);script.setAttribute("type","text/javascript");document.body.appendChild(script);}
_LTKClick.prototype.CallBack=function(data){try{this.SetCookie("_trkt",data.token,365,this._roothost,"/",null);if(window.jQuery&&_ltk.browser.safari){jQuery("body").append('<iframe id="ctidf" name="ctidf" style="display:none;"></iframe><form id="ctidfr" enctype="application/x-www-form-urlencoded" action="'+this._protocol+this._endpoint+'/CTIDF.ashx" target="ctidf" action="post"><input type="hidden" name="trkt" id="trkt" value="'+data.token+'"/><input type="hidden" name="hctid" id="hctid" value="'+_ltk.Client.CTID+'"/></form>');jQuery("#ctidfr").submit();}}
catch(ex){_ltk.Exception.Submit(ex,'Click Callback');}}}


function _LTKSubscriber(){this.List=null;this.Settings=null;this.Email=null;this.UpdatedEmail=null;this.Profile=new _Profile();this._endpoint='s1.listrakbi.com/t';this._protocol=("https:"==document.location.protocol)?"https://":"http://";_LTKSubscriber.prototype.Submit=function(){var q='ctid='+_ltk.Client.CTID+'&uid='+_ltk.uuidCompact()+'&_t_0=s'+
(this.Email==null?'':'&e_0='+encodeURIComponent(this.Email))+
(this.UpdatedEmail==null?'':'&u_0='+encodeURIComponent(this.UpdatedEmail))+
(this.List==null?'':'&l_0='+encodeURIComponent(this.List))+
(this.Settings==null?'':'&s_0='+encodeURIComponent(this.Settings));if(this.Profile.Items.length>0){for(var i in this.Profile.Items){var p=this.Profile.Items[i];if(p.AttributeID!=null&&p.Value!=null){q+='&'+encodeURIComponent(p.AttributeID)+'_0='+encodeURIComponent(p.Value);}}}
var loc=this._protocol+this._endpoint+'/S.ashx?'+q;var img=new Image();img.width=1;img.height=1;img.src=loc;}}
function _Profile(){this.Items=new Array();_Profile.prototype.Add=function(attr_id,value){var p=new _ProfileItem();p.AttributeID=attr_id;p.Value=value;this.Items.push(p);}}
function _ProfileItem(){this.AttributeID=null;this.Value=null;}

var _ltkwmt = '';
function isWatermark(wmt) {
    if(!_ltkwmt || _ltkwmt.length == 0) {
        return false;
    }
    if(_ltkwmt.indexOf(wmt) >= 0) { 
        return true; 
    }
    else { return false; }
}


function SessionTracker(){this.Assembler=new _Assembler();this.userData=new UserData;this.items=new Array();this.domain=null;this.initialized=false;this.submitQueued=false;this.sessionID;this.tid;this.clearCart=false;this.debug=false;this.FirstName=null;this.LastName=null;this.Email=null;this.Stage=null;this.OrderNumber=null;this.Total=null;this.Meta1=null;this.Meta2=null;this.Token=null;this.CartLink=null;this.Source=null;this.trkt=null;this._varmap={'_type':'_st','Email':'e','FirstName':'fn','LastName':'ln','Meta1':'sm1','Meta2':'sm2','Stage':'st','OrderNumber':'on','Total':'tt','Token':'tk','Source':'sr','CartLink':'cl','NewCustomer':'nc','clearCart':'cc'};function UserData(){this._varmap={};}
SessionTracker.prototype.Load=function(trackerID){try{var sid=this.getCookie("STSID"+trackerID);this.tid=trackerID;if(sid){this.sessionID=sid;}
this.trkt=this.getCookie("_trkt");this.debug=this.getCookie("STSD"+trackerID)=="1"?true:false;if(location.search.indexOf('__std=1')>0){this.debug=true;}
else if(location.search.indexOf('__std=0')>0){this.debug=false;}
var _stli2=setInterval(function(){if(!window.jQuery){return;}
clearInterval(_stli2);var getTemplateAsyncCall=_ltk.AsyncManager.StartAsyncCall('scaGetTemplate');jQuery.getJSON(_protocol+"sca1.listrakbi.com/Handlers/GetTemplate.ashx?_sid="+sid+"&_tid="+trackerID+"&_t="+new Date().valueOf()+"&callback=?",function(data){try{_ltk.SCA.domain=getCookieDomain();_ltk.SCA.sessionID=data.sessionID;_ltk.SCA.setCookie("STSD"+trackerID,_ltk.SCA.debug?"1":"0",365,_ltk.SCA.domain);_ltk.SCA.setCookie("STSID"+trackerID,data.sessionID,365,_ltk.SCA.domain);_ltk.AsyncManager.CallComplete('scaGetTemplate');_ltk.SCA.initialized=true;if(_ltk.SCA.submitQueued){_ltk.SCA.submitQueued=false;_ltk.SCA.Submit();}
jQuery().ready(function(){try{if(_ltk.browser.safari){jQuery("body").append('<iframe id="ifscasidframe" name="ifscasidframe" style="display:none;"></iframe><form id="ifscasidform" enctype="application/x-www-form-urlencoded" action="'+_protocol+'sca1.listrakbi.com/Handlers/CTID.ashx" target="ifscasidframe" action="post"><input type="hidden" name="ifscasid" id="ifscasid" value="'+_ltk.SCA.sessionID+'"/><input type="hidden" name="a" id="a" value="s"/><input type="hidden" name="tid" id="tid" value="'+_ltk.SCA.tid+'"/></form>');jQuery("#ifscasidform").submit();}}
catch(ex){_ltk.Exception.Submit(ex,'ifscasid');}});}
catch(ex){_ltk.Exception.Submit(ex,'GetTemplate Callback');}});},100);}
catch(ex){_ltk.Exception.Submit(ex,'Load');}}
SessionTracker.prototype.SetCustomer=function(email,firstname,lastname){if(email){this.Email=email;}
if(firstname){this.FirstName=firstname;}
if(lastname){this.LastName=lastname;}}
SessionTracker.prototype.CaptureEmail=function(id){try{var _stsi1=setInterval(function(){if(!window.jQuery){return;}
clearInterval(_stsi1);if(typeof id=="undefined"||id==""){return;}
var _sl=jQuery("[id='"+id+"']");if(_sl.length==0){_sl=jQuery("input[name='"+id+"']");}
if(_sl.length){_sl.change(function(){if(jQuery(_sl).val().length>0&&!isWatermark(jQuery(_sl).val())&&_ltk.isValidEmail(jQuery(_sl).val())){_ltk.SCA.Update("email",jQuery(this).val());}});if(jQuery(_sl).val().length>0&&!isWatermark(jQuery(_sl).val())&&_ltk.isValidEmail(jQuery(_sl).val())){_ltk.SCA.Update("email",jQuery(_sl).val());}}},100);}
catch(ex){_ltk.Exception.Submit(ex,'CaptureEmail');}}
SessionTracker.prototype.AddItem=function(sku,quantity,price,name){this.items.push(new SCAItem(sku,quantity,price,name));}
SessionTracker.prototype.AddItemWithLinks=function(sku,quantity,price,name,imageurl,linkurl){try{var _ni=new SCAItem(sku,quantity,price,name);_ni.ImageUrl=imageurl;_ni.LinkUrl=linkurl;this.items.push(_ni);}
catch(ex){_ltk.Exception.Submit(ex,'Add Item With Links');}}
SessionTracker.prototype.AddItemEx=function(item){this.items.push(item);}
SessionTracker.prototype.Update=function(k,v){try{var _scuir=0;var _scui=setInterval(function(){if(!_ltk.SCA.sessionID&&_scuir<6){_scuir++;return;}
clearInterval(_scui);var _uimg=new Image();jQuery(_uimg).error(function(e){_ltk.Exception.Submit({name:"ex"},'Update Image');});_uimg.src=_protocol+'sca1.listrakbi.com/Handlers/Update.ashx?_sid='+_ltk.SCA.sessionID+'&_uid='+_ltk.uuidCompact()+'&_tid='+_ltk.SCA.tid+"&"+k+"="+v+"&_t="+new Date().valueOf();},500);}
catch(ex){_ltk.Exception.Submit(ex,'Update');}}
SessionTracker.prototype.SetData=function(k,v){if(v){this.userData[k.toLowerCase()]=v;if(!this.userData._varmap[k])this.userData._varmap[k]=k;}}
SessionTracker.prototype.ClearCart=function(){this.clearCart=true;this.Submit();}
SessionTracker.prototype.Submit=function(){try{if(!this.initialized){this.submitQueued=true;return;}
if(typeof this.sessionID=="undefined"){return;}
if(this.getCookie("_trkt")!=""){this.Token=this.getCookie("_trkt");}
this.Assembler=new _Assembler();this.Assembler.QueryMode=1;this.Assembler.EndPointArray=['sca1.listrakbi.com/','sca2.listrakbi.com/'];this.Assembler.EndPointPath='Handlers/Set.ashx';this.Assembler.QueryHeader='_sid='+this.sessionID+'&_tid='+this.tid+'&_uid='+_ltk.uuidCompact();this.Assembler.AddObject(this);if(this.OrderNumber==null){this.Assembler.AddArrayObject(this.items);}
if(this.userData){this.Assembler.AddObject(this.userData);}
this.Assembler.Flush();if(this.OrderNumber!=null){_ltk.SCA.setCookie("STSID"+this.tid,"",-1,this.domain);try{if(window.jQuery&&_ltk.browser.safari){jQuery("body").append('<iframe id="ifscasidframec" name="ifscasidframec" style="display:none;"></iframe><form id="ifscasidformc" enctype="application/x-www-form-urlencoded" action="'+_protocol+'sca1.listrakbi.com/Handlers/CTID.ashx" target="ifscasidframec" action="post"><input type="hidden" name="ifscasid" id="ifscasid" value="'+_ltk.SCA.sessionID+'"/><input type="hidden" name="a" id="a" value="c"/><input type="hidden" name="tid" id="tid" value="'+_ltk.SCA.tid+'"/></form>');jQuery("#ifscasidformc").submit();}}
catch(ex){_ltk.Exception.Submit(ex,'ifscasidc');}}
this.Reset();}
catch(ex){_ltk.Exception.Submit(ex,'Submit');}}
SessionTracker.prototype.getCookie=function(c_name){if(document.cookie.length>0){c_start=document.cookie.indexOf(c_name+"=");if(c_start!=-1){c_start=c_start+c_name.length+1;c_end=document.cookie.indexOf(";",c_start);if(c_end==-1)c_end=document.cookie.length;return unescape(document.cookie.substring(c_start,c_end));}}
return"";}
SessionTracker.prototype.setCookie=function(c_name,value,expiredays,domain){var exdate=new Date();exdate.setDate(exdate.getDate()+expiredays);document.cookie=c_name+"="+escape(value)+
((expiredays==null)?"":";expires="+exdate.toGMTString()+";domain="+domain+";path=/;");}
SessionTracker.prototype.Reset=function(){this.items=new Array();this.clearCart=false;}}
function SCAItem(sku,quantity,price,name){this.Sku=sku;this.Quantity=quantity;this.Price=price;this.Name=name;this.ImageUrl=null;this.LinkUrl=null;this.Size=null;this.Meta1=null;this.Meta2=null;this._isIndexable=true;this._varmap={'_type':'_i','Sku':'s','Quantity':'q','Price':'p','Name':'n','ImageUrl':'iu','LinkUrl':'lu','Size':'sz','Meta1':'m1','Meta2':'m2'};}
function getCookieDomain(){var rdhRESM=window.location.host.match(/([\.]*[^\.]+\.(co\.uk|com|net|biz|org|co\.nz|info|jp|edu|mx|com\.br|es|ca|pro|co|au)$)|(^localhost$)/gi);if(rdhRESM){if(rdhRESM[0].indexOf(".")!=0){return"."+rdhRESM[0];}
else{return rdhRESM[0];}}
else{return window.location.host;}}


function _ActivityList(){this.Assembler=new _Assembler();this.Activity=new Array();this.MerchantTrackingID=null;this.GlobalSessionID=null;this.SessionID=null;this.TrackingToken=null;this._varmap={'GlobalSessionID':'gsid','SessionID':'sid','TrackingToken':'trkt'};}
function Activity(){this._type='at';this._isIndexable=true;this.ActivityType='browse';this.Sku=null;this.Price=null;this.LinkURL=null;this.ImageURL=null;this.ActivityData=null;this.VisitedPage=getUrlParts(window.location).pathname;this._varmap={'_type':'_t','ActivityType':'t','Sku':'s','ActivityData':'d','VisitedPage':'pg'};}
_ActivityList.prototype.Load=function(){var TrackerID='';this.TrackingToken=_ltk.GetCookie("_trkt");this.MerchantTrackingID='hlap7U2sbq8H';this.SessionID=_ltk.SCA.SessionID;if(this.SessionID==null)
this.SessionID=_ltk.GetCookie("STSID"+TrackerID);this.GlobalSessionID=_ltk.GetCookie("_gsid");if(this.GlobalSessionID==null){this.GetGSID();}}
_ActivityList.prototype.AddActivity=function(ActivityType,Sku){var _activity=new Activity;_activity.ActivityType=ActivityType;if(Sku!=undefined)
_activity.Sku=Sku;this.Activity.push(_activity);}
_ActivityList.prototype.AddActivityEx=function(Activity){this.Activity.push(Activity);}
_ActivityList.prototype.Submit=function(){this.Load();_ltk.AsyncManager.StartAsyncCall('submitActivity',function(){try{if(typeof _ltk.Activity.SessionID=="undefined"){return;}
_ltk.Activity.Assembler=new _Assembler();_ltk.Activity.Assembler.QueryMode=1;_ltk.Activity.Assembler.EndPointArray=new Array();_ltk.Activity.Assembler.EndPointArray.push('at1.listrakbi.com');_ltk.Activity.Assembler.EndPointPath='/Handlers/Set.ashx';_ltk.Activity.Assembler.QueryHeader='ctid='+_ltk.Activity.MerchantTrackingID+'&uid='+_ltk.uuidCompact();_ltk.Activity.Assembler.AddObject(_ltk.Activity);_ltk.Activity.Assembler.AddArrayObject(_ltk.Activity.Activity);_ltk.Activity.Assembler.Flush();_ltk.Activity.Activity.length=0;}
catch(ex){_ltk.Exception.Submit(ex,'Submit');}},['getGSID','clickSubmit','scaGetTemplate']);}
function getUrlParts(url){var a=document.createElement('a');a.href=url;return{href:a.href,host:a.host,hostname:a.hostname,port:a.port,pathname:a.pathname,protocol:a.protocol,hash:a.hash,search:a.search};}
_ActivityList.prototype.GetGSID=function(){var gsidAsyncCall=_ltk.AsyncManager.StartAsyncCall('getGSID');try{jQuery.getJSON(_protocol+"at1.listrakbi.com/Handlers/GetGSID.ashx?callback=?",function(data){try{_ltk.Activity.GlobalSessionID=data.gsid;_ltk.Click.SetCookie("_gsid",data.gsid,365,getCookieDomain(),"/",null);}
catch(ex){_ltk.Exception.Submit(ex,'GetGSID Callback');}
_ltk.AsyncManager.CallComplete('getGSID');});}
catch(ex){_ltk.Exception.Submit(ex,'GetGSID');gsidAsyncCall.Complete();}}


function _Alerts(){this.Assembler=new _Assembler();this.Alert=new Array();this.MerchantTrackingID='';this._varmap={};}
function Alert(){this._type='al';this._isIndexable=true;this.Email='';this.Sku='';this.AlertCode='';this._varmap={'_type':'_t','Email':'e','Sku':'s','AlertCode':'ac'};}
_Alerts.prototype.AddAlert=function(Email,Sku,AlertCode){var _alert=new Alert;_alert.Email=Email;_alert.Sku=Sku;_alert.AlertCode=AlertCode;this.Alert.push(_alert);}
_Alerts.prototype.AddAlertEx=function(Alert){this.Alert.push(Alert);}
_Alerts.prototype.Load=function(){this.MerchantTrackingID='hlap7U2sbq8H';}
_Alerts.prototype.Submit=function(){try{this.Load();this.Assembler=new _Assembler();this.Assembler.QueryMode=1;this.Assembler.EndPointArray=new Array();this.Assembler.EndPointArray.push('al1.listrakbi.com');this.Assembler.EndPointPath='/Handlers/Set.ashx';this.Assembler.QueryHeader='ctid='+this.MerchantTrackingID+'&uid='+_ltk.uuidCompact();this.Assembler.AddObject(this);this.Assembler.AddArrayObject(this.Alert);this.Assembler.Flush();this.Alert.length=0;}
catch(ex){_ltk.Exception.Submit(ex,'Submit');}}

if(typeof _ltk == "undefined")
{
    var _ltk = new LTK();
    _ltk.Client.CTID = "hlap7U2sbq8H";
    
}
















_ltk.Modal={modals:[],autoload:[],active:false,load:function(name){this.autoload.push(name);}};var _msi=setInterval(function(){if(!window.jQuery){return;}
clearInterval(_msi);;(function(factory){if(typeof define==='function'&&define.amd){define(['jquery'],factory);}else{factory(jQuery);}}
(function(jQuery){var d=[],doc=jQuery(document),ua=navigator.userAgent.toLowerCase(),wndw=jQuery(window),w=[];var browser={ieQuirks:null,msie:/msie/.test(ua)&&!/opera/.test(ua),opera:/opera/.test(ua)};browser.ie6=browser.msie&&/msie 6./.test(ua)&&typeof window['XMLHttpRequest']!=='object';browser.ie7=browser.msie&&/msie 7.0/.test(ua);jQuery.ltkmodal=function(data,options){return jQuery.ltkmodal.impl.init(data,options);};jQuery.ltkmodal.close=function(){jQuery.ltkmodal.impl.close();};jQuery.ltkmodal.focus=function(pos){jQuery.ltkmodal.impl.focus(pos);};jQuery.ltkmodal.setContainerDimensions=function(){jQuery.ltkmodal.impl.setContainerDimensions();};jQuery.ltkmodal.setPosition=function(){jQuery.ltkmodal.impl.setPosition();};jQuery.ltkmodal.update=function(height,width){jQuery.ltkmodal.impl.update(height,width);};jQuery.fn.ltkmodal=function(options){return jQuery.ltkmodal.impl.init(this,options);};jQuery.ltkmodal.defaults={appendTo:'body',focus:true,opacity:50,overlayId:'simpleltkmodal-overlay',overlayCss:{},containerId:'simpleltkmodal-container',containerCss:{},dataId:'simpleltkmodal-data',dataCss:{},minHeight:null,minWidth:null,maxHeight:null,maxWidth:null,autoResize:false,autoPosition:true,zIndex:1000,close:true,closeHTML:'<a class="modalCloseImg" title="Close"></a>',closeClass:'simpleltkmodal-close',escClose:true,overlayClose:false,fixed:true,position:null,persist:false,modal:true,onOpen:null,onShow:null,onClose:null};jQuery.ltkmodal.impl={d:{},init:function(data,options){var s=this;if(s.d.data){return false;}
browser.ieQuirks=browser.msie&&document.compatMode=="BackCompat";s.o=jQuery.extend({},jQuery.ltkmodal.defaults,options);s.zIndex=s.o.zIndex;s.occb=false;if(typeof data==='object'){data=data instanceof jQuery?data:jQuery(data);s.d.placeholder=false;if(data.parent().parent().size()>0){data.before(jQuery('<span></span>').attr('id','simpleltkmodal-placeholder').css({display:'none'}));s.d.placeholder=true;s.display=data.css('display');if(!s.o.persist){s.d.orig=data.clone(true);}}}
else if(typeof data==='string'||typeof data==='number'){data=jQuery('<div></div>').html(data);}
else{alert('SimpleLtkModal Error: Unsupported data type: '+typeof data);return s;}
s.create(data);data=null;s.open();if(jQuery.isFunction(s.o.onShow)){s.o.onShow.apply(s,[s.d]);}
return s;},create:function(data){var s=this;s.getDimensions();if(s.o.modal&&browser.ie6){s.d.iframe=jQuery('<iframe src="javascript:false;"></iframe>').css(jQuery.extend(s.o.iframeCss,{display:'none',opacity:0,position:'fixed',height:w[0],width:w[1],zIndex:s.o.zIndex,top:0,left:0})).appendTo(s.o.appendTo);}
s.d.overlay=jQuery('<div></div>').attr('id',s.o.overlayId).addClass('simpleltkmodal-overlay').css(jQuery.extend(s.o.overlayCss,{display:'none',opacity:s.o.opacity/100,height:s.o.modal?d[0]:0,width:s.o.modal?d[1]:0,position:'fixed',left:0,top:0,zIndex:s.o.zIndex+1})).appendTo(s.o.appendTo);s.d.container=jQuery('<div></div>').attr('id',s.o.containerId).addClass('simpleltkmodal-container').css(jQuery.extend({position:s.o.fixed?'fixed':'absolute'},s.o.containerCss,{display:'none',zIndex:s.o.zIndex+2})).append(s.o.close&&s.o.closeHTML?jQuery(s.o.closeHTML).addClass(s.o.closeClass):'').appendTo(s.o.appendTo);s.d.wrap=jQuery('<div></div>').attr('tabIndex',-1).addClass('simpleltkmodal-wrap').css({height:'100%',outline:0,width:'100%'}).appendTo(s.d.container);s.d.data=data.attr('id',data.attr('id')||s.o.dataId).addClass('simpleltkmodal-data').css(jQuery.extend(s.o.dataCss,{display:'none'})).appendTo('body');data=null;s.setContainerDimensions();s.d.data.appendTo(s.d.wrap);if(browser.ie6||browser.ieQuirks){s.fixIE();}},bindEvents:function(){var s=this;jQuery('.'+s.o.closeClass).bind('click.simpleltkmodal',function(e){e.preventDefault();s.close();});if(s.o.modal&&s.o.close&&s.o.overlayClose){s.d.overlay.bind('click.simpleltkmodal',function(e){e.preventDefault();s.close();});}
doc.bind('keydown.simpleltkmodal',function(e){if(s.o.modal&&e.keyCode===9){s.watchTab(e);}
else if((s.o.close&&s.o.escClose)&&e.keyCode===27){e.preventDefault();s.close();}});},unbindEvents:function(){jQuery('.'+this.o.closeClass).unbind('click.simpleltkmodal');doc.unbind('keydown.simpleltkmodal');wndw.unbind('.simpleltkmodal');this.d.overlay.unbind('click.simpleltkmodal');},fixIE:function(){var s=this,p=s.o.position;jQuery.each([s.d.iframe||null,!s.o.modal?null:s.d.overlay,s.d.container.css('position')==='fixed'?s.d.container:null],function(i,el){if(el){var bch='document.body.clientHeight',bcw='document.body.clientWidth',bsh='document.body.scrollHeight',bsl='document.body.scrollLeft',bst='document.body.scrollTop',bsw='document.body.scrollWidth',ch='document.documentElement.clientHeight',cw='document.documentElement.clientWidth',sl='document.documentElement.scrollLeft',st='document.documentElement.scrollTop',s=el[0].style;s.position='absolute';if(i<2){s.removeExpression('height');s.removeExpression('width');s.setExpression('height',''+bsh+' > '+bch+' ? '+bsh+' : '+bch+' + "px"');s.setExpression('width',''+bsw+' > '+bcw+' ? '+bsw+' : '+bcw+' + "px"');}
else{var te,le;if(p&&p.constructor===Array){var top=p[0]?typeof p[0]==='number'?p[0].toString():p[0].replace(/px/,''):el.css('top').replace(/px/,'');te=top.indexOf('%')===-1?top+' + (t = '+st+' ? '+st+' : '+bst+') + "px"':parseInt(top.replace(/%/,''))+' * (('+ch+' || '+bch+') / 100) + (t = '+st+' ? '+st+' : '+bst+') + "px"';if(p[1]){var left=typeof p[1]==='number'?p[1].toString():p[1].replace(/px/,'');le=left.indexOf('%')===-1?left+' + (t = '+sl+' ? '+sl+' : '+bsl+') + "px"':parseInt(left.replace(/%/,''))+' * (('+cw+' || '+bcw+') / 100) + (t = '+sl+' ? '+sl+' : '+bsl+') + "px"';}}
else{te='('+ch+' || '+bch+') / 2 - (this.offsetHeight / 2) + (t = '+st+' ? '+st+' : '+bst+') + "px"';le='('+cw+' || '+bcw+') / 2 - (this.offsetWidth / 2) + (t = '+sl+' ? '+sl+' : '+bsl+') + "px"';}
s.removeExpression('top');s.removeExpression('left');s.setExpression('top',te);s.setExpression('left',le);}}});},focus:function(pos){var s=this,p=pos&&jQuery.inArray(pos,['first','last'])!==-1?pos:'first';var input=jQuery(':input:enabled:visible:'+p,s.d.wrap);setTimeout(function(){input.length>0?input.focus():s.d.wrap.focus();},10);},getDimensions:function(){var s=this,h=typeof window.innerHeight==='undefined'?wndw.height():window.innerHeight;d=[doc.height(),doc.width()];w=[h,wndw.width()];},getVal:function(v,d){return v?(typeof v==='number'?v:v==='auto'?0:v.indexOf('%')>0?((parseInt(v.replace(/%/,''))/100)*(d==='h'?w[0]:w[1])):parseInt(v.replace(/px/,''))):null;},update:function(height,width){var s=this;if(!s.d.data){return false;}
s.d.origHeight=s.getVal(height,'h');s.d.origWidth=s.getVal(width,'w');s.d.data.hide();height&&s.d.container.css('height',height);width&&s.d.container.css('width',width);s.setContainerDimensions();s.d.data.show();s.o.focus&&s.focus();s.unbindEvents();s.bindEvents();},setContainerDimensions:function(){var s=this,badIE=browser.ie6||browser.ie7;var ch=s.d.origHeight?s.d.origHeight:browser.opera?s.d.container.height():s.getVal(badIE?s.d.container[0].currentStyle['height']:s.d.container.css('height'),'h'),cw=s.d.origWidth?s.d.origWidth:browser.opera?s.d.container.width():s.getVal(badIE?s.d.container[0].currentStyle['width']:s.d.container.css('width'),'w'),dh=s.d.data.outerHeight(true),dw=s.d.data.outerWidth(true);s.d.origHeight=s.d.origHeight||ch;s.d.origWidth=s.d.origWidth||cw;var mxoh=s.o.maxHeight?s.getVal(s.o.maxHeight,'h'):null,mxow=s.o.maxWidth?s.getVal(s.o.maxWidth,'w'):null,mh=mxoh&&mxoh<w[0]?mxoh:w[0],mw=mxow&&mxow<w[1]?mxow:w[1];var moh=s.o.minHeight?s.getVal(s.o.minHeight,'h'):'auto';if(!ch){if(!dh){ch=moh;}
else{if(dh>mh){ch=mh;}
else if(s.o.minHeight&&moh!=='auto'&&dh<moh){ch=moh;}
else{ch=dh;}}}
else{ch=s.o.autoResize&&ch>mh?mh:ch<moh?moh:ch;}
var mow=s.o.minWidth?s.getVal(s.o.minWidth,'w'):'auto';if(!cw){if(!dw){cw=mow;}
else{if(dw>mw){cw=mw;}
else if(s.o.minWidth&&mow!=='auto'&&dw<mow){cw=mow;}
else{cw=dw;}}}
else{cw=s.o.autoResize&&cw>mw?mw:cw<mow?mow:cw;}
s.d.container.css({height:ch,width:cw});s.d.wrap.css({overflow:(dh>ch||dw>cw)?'auto':'visible'});s.o.autoPosition&&s.setPosition();},setPosition:function(){var s=this;s.d.container.css({left:"50%",top:"20%","margin-left":(-1*s.d.container.outerWidth(false)/2)});},watchTab:function(e){var s=this;if(jQuery(e.target).parents('.simpleltkmodal-container').length>0){s.inputs=jQuery(':input:enabled:visible:first, :input:enabled:visible:last',s.d.data[0]);if((!e.shiftKey&&e.target===s.inputs[s.inputs.length-1])||(e.shiftKey&&e.target===s.inputs[0])||s.inputs.length===0){e.preventDefault();var pos=e.shiftKey?'last':'first';s.focus(pos);}}
else{e.preventDefault();s.focus();}},open:function(){var s=this;s.d.iframe&&s.d.iframe.show();if(jQuery.isFunction(s.o.onOpen)){s.o.onOpen.apply(s,[s.d]);}
else{s.d.overlay.show();s.d.container.show();s.d.data.show();}
s.o.focus&&s.focus();s.bindEvents();},close:function(){var s=this;if(!s.d.data){return false;}
s.unbindEvents();if(jQuery.isFunction(s.o.onClose)&&!s.occb){s.occb=true;s.o.onClose.apply(s,[s.d]);}
else{if(s.d.placeholder){var ph=jQuery('#simpleltkmodal-placeholder');if(s.o.persist){ph.replaceWith(s.d.data.removeClass('simpleltkmodal-data').css('display',s.display));}
else{s.d.data.hide().remove();ph.replaceWith(s.d.orig);}}
else{s.d.data.hide().remove();}
s.d.container.hide().remove();s.d.overlay.hide();s.d.iframe&&s.d.iframe.hide().remove();s.d.overlay.remove();s.d={};}}};}));
var LTKModal=function(opts){this.initDelay=0;this.followupDelay=0;this.autoClose=0;this.formHTML="";this.confHTML="";this.redirUrl="";this.subCode="";this.urlMode="";this.urlRules=[];this.name="";this.uaSuppression="";this.testMode=false;this.autoload=false;this.overlayClose=false;jQuery.extend(this,opts);this.subCookieName="ltkmodal-sub-"+this.subCode;this.followupCookieName="ltkmodal-"+this.subCode;};LTKModal.prototype.load=function(){try{var self=this,urlMatch=false;if(self.testMode&&!/ltkmodaltestmode/gi.test(document.location.href)){return;}
if(!self.checkCookie(self.followupCookieName,self.followupDelay)||_ltk.cookie(self.subCookieName)){return;}
if(self.newSessionsOnly&&/[?&]trk_msg=/gi.test(document.location.href)&&_ltk.moduleList.indexOf(_ltk.urlParam("trk_module").toUpperCase())<0){var _dt=new Date();_dt.setSeconds(_dt.getSeconds()+315360000);_ltk.cookie(self.followupCookieName,new Date().toUTCString(),{expires:_dt,path:"/"});return;}
for(var ri=0;ri<self.urlRules.length;ri++){urlMatch=new RegExp(self.urlRules[ri],"gi").test(document.location.href);if(self.urlMode=="0"&&urlMatch){return;}
else if(self.urlMode=="1"&&urlMatch){break;}}
if((self.urlMode=="0"||urlMatch)&&!_ltk.Modal.active){_ltk.Modal.active=true;var mdlshow=(function(ltkmdl){return(function(){ltkmdl.show();});}(self));setTimeout(mdlshow,self.initDelay);}}
catch(ex){_ltk.Exception.Submit(ex,'Modal Load');}};LTKModal.prototype.show=function(){try{var self=this;if(!_ltk.cookiesEnabled()){return;}
var _dt=new Date();_dt.setSeconds(_dt.getSeconds()+315360000);_ltk.cookie(self.followupCookieName,new Date().toUTCString(),{expires:_dt,path:"/"});jQuery("body").append("<div id=\"ltkmodal-content\"><div id=\"ltkmodal-form\">"+self.formHTML+"</div></div>");jQuery("#ltkmodal-content").append("<div id=\"ltkmodal-thanks\" style=\"display:none;\">"+self.confHTML+"</div>");if(_ltk.SCA.tid){if(jQuery("#ltkmodal-content .ltkmodal-email").length){jQuery("#ltkmodal-content .ltkmodal-email").change(function(){_ltk.SCA.Update('email',jQuery(this).val());});}}
jQuery("#ltkmodal-content").ltkmodal({closeClass:"ltkmodal-close",overlayClose:self.overlayClose,overlayCss:{backgroundColor:"#000"},overlayId:'ltkmodal-overlay',containerId:'ltkmodal-container',dataId:'ltkmodal-data',onOpen:function(dialog){_ltk.Modal.active=true;dialog.overlay.fadeIn('fast',function(){dialog.container.fadeIn('fast',function(){dialog.data.fadeIn('fast');});});dialog.data.find(".ltkmodal-subscribe").click(function(){self.submit();});},onClose:function(dialog){_ltk.Modal.active=false;dialog.container.fadeOut('fast',function(){dialog.overlay.fadeOut('fast',function(){jQuery.ltkmodal.close();jQuery('#ltkmodal-content').remove();});});}});jQuery(document).trigger("ltkmodal.show");}
catch(ex){_ltk.Exception.Submit(ex,'Modal Show');}};LTKModal.prototype.submit=function(){try{var self=this;var _dt=new Date();_dt.setMinutes(_dt.getMinutes()+(10*365*24*60));_ltk.cookie(self.subCookieName,new Date().toUTCString(),{expires:_dt,path:"/"});jQuery("#ltkmodal-content input, #ltkmodal-content select").each(function(i,v){var inputType=jQuery(v).attr("type");if(inputType=="radio"){if(jQuery(v).attr("checked")){_ltk.Subscriber.Profile.Add(jQuery(v).attr("name").replace(/RadioButton./i,"")+"."+jQuery(v).val(),"on");}
else{_ltk.Subscriber.Profile.Add(jQuery(v).attr("name").replace(/RadioButton./i,"")+"."+jQuery(v).val(),"off");}}
else if(inputType=="checkbox"){if(jQuery(v).attr("checked")){_ltk.Subscriber.Profile.Add(jQuery(v).attr("name").replace(/CheckBox./i,""),"on");}
else{_ltk.Subscriber.Profile.Add(jQuery(v).attr("name").replace(/CheckBox./i,""),"off");}}
else{if(jQuery(v).attr("class")&&jQuery(v).attr("class").match(/email/gi)){_ltk.Subscriber.Email=jQuery(v).val();if(_ltk.SCA&&_ltk.SCA.sessionID){_ltk.SCA.SetCustomer(jQuery(v).val(),"","");_ltk.SCA.Submit();}}
else if(jQuery(v).attr("name")&&jQuery(v).attr("name").substring(0,9).toLowerCase()!="checkbox."&&jQuery(v).attr("name").substring(0,12).toLowerCase()!="radiobutton."){_ltk.Subscriber.Profile.Add(jQuery(v).attr("name"),jQuery(v).val());}}});_ltk.Subscriber.List=self.subCode;_ltk.Subscriber.Submit();jQuery("#ltkmodal-container").css("height","auto");jQuery("#ltkmodal-content #ltkmodal-form").fadeOut('fast',function(e){if(self.redirUrl){window.location=self.redirUrl;}
else{jQuery("#ltkmodal-content #ltkmodal-thanks").fadeIn('fast',function(e){if(self.autoClose>0){window.setTimeout(function(){if(_ltk.Modal.active){jQuery.ltkmodal.close();}},self.autoClose*1000);}});}});}
catch(ex){_ltk.Exception.Submit(ex,'Modal Submit');}};LTKModal.prototype.checkCookie=function(cname,seconds){var ck=_ltk.cookie(cname);if(!ck){return true;}
var lmdt=new Date(ck);if(isNaN(lmdt.getTime())){return true;}
lmdt.setSeconds(lmdt.getSeconds()+seconds);return lmdt<new Date();};LTKModal.prototype.userAgentSuppression=function(){if(this.uaSuppression.length>0){var i;var userAgents=new Array();var isMobile={AndroidPhone:(navigator.userAgent.toLowerCase().search("android")>-1)&&(navigator.userAgent.toLowerCase().search("mobile")>-1),AndroidTablet:(navigator.userAgent.toLowerCase().search("android")>-1)&&!(navigator.userAgent.toLowerCase().search("mobile")>-1),iOSiPhone:navigator.userAgent.match(/iPhone/i),iOSiPad:navigator.userAgent.match(/iPad/i),iOSiPod:navigator.userAgent.match(/iPod/i),OperaMini:navigator.userAgent.match(/Opera Mini/i),IEMobile:navigator.userAgent.match(/IEMobile/i)};userAgents=this.uaSuppression.split(',');for(i=0;i<userAgents.length;i++){switch(userAgents[i]){case"AndroidTablet":if(isMobile.AndroidTablet)
return true;else
break;case"AndroidPhone":if(isMobile.AndroidPhone)
return true;else
break;case"OperaMini":if(isMobile.OperaMini)
return true;else
break;case"IEMobile":if(isMobile.IEMobile)
return true;else
break;case"IosIpod":if(isMobile.iOSiPod)
return true;else
break;case"IosIpad":if(isMobile.iOSiPad)
return true;else
break;case"IosIphone":if(isMobile.iOSiPhone)
return true;else
break;}}}}
_ltk.Modal.suppress=function(){if(_ltk.browser.msie&&(_ltk.browser.version<7||document.compatMode=="BackCompat")||((window.location.search.search(/gclid=/i)!=-1)))
return true;else
return false;}
_ltk.Modal.add=function(opts){this.modals.push(new LTKModal(opts));};_ltk.Modal.load=function(name){if(!_ltk.Modal.suppress()){for(var i=0;i<this.modals.length;i++){if(!this.modals[i].userAgentSuppression()&&((!name&&this.modals[i].autoload)||this.modals[i].name===name)){this.modals[i].load();if(name){return;}}}}};_ltk.Modal.add({ newSessionsOnly: true, initDelay: 3000, followupDelay: 3888000, autoClose: 0, formHTML: "<!-- Form: BEGIN --> <div id=\"modal-wrapper\"> <div id=\"modal-content\"> <a href=\"#\" class=\"ltkmodal-close close-button\">X</a> <h1>Sign Up and Save!</h1> <div class=\"left float-left\"> <p>Get <strong>10% off any size order</strong> when you sign up for our newsletter, \"The Critical Thinker\".</p> <div class=\"field\"> <input type=\"text\" id=\"ltkmodal-email\" class=\"textbox ltkmodal-email\" name=\"email\" size=\"40\" maxlength=\"100\" value=\"Email Address\" onFocus=\"if (this.value == 'Email Address') this.value = '';\" onBlur=\"if (this.value == '') this.value = 'Email Address';\" /> </div> <div class=\"field\"> <input type=\"text\" class=\"textbox\" name=\"Profile.First Name\" maxlength=\"50\" value=\"First Name\" onFocus=\"if (this.value == 'First Name') this.value = '';\" onBlur=\"if (this.value == '') this.value = 'First Name';\" /> </div> <h3>What best describes you?</h3> <div class=\"field select-wrapper\"> <select name=\"Profile.Market\" class=\"dropdown\"> <option value=\"off\"> - select option - </option> <option value=\"Parent\">Parent</option> <option value=\"Home Educator\">Home Educator</option> <option value=\"Classroom Educator\">Classroom Educator</option> </select> </div> <div class=\"field\"> <input type=\"hidden\" class=\"text\" name=\"Source.Modal\" size=\"40\" maxlength=\"100\" value=\"On\" /> </div> <div class=\"buttons\"> <button type=\"submit\" class=\"ltkmodal-subscribe\">Sign Up</button> <button type=\"button\" class=\"ltkmodal-close ltkmodal-no-thanks\">No thanks</button> </div> </div> </div> </div> <style type=\"text/css\"> #modal-wrapper { width: 338px; background-color: #fff; border: 8px solid #FFFFFF; border-radius: 20px; box-shadow: 0px 0px 24px rgba(0,0,0,.75); -webkit-box-shadow: 0px 0px 24px rgba(0,0,0,.75); -moz-box-shadow: 0px 0px 24px rgba(0,0,0,.75); font-size: 100%; -webkit-text-size-adjust: 100%; -ms-text-size-adjust: 100%; } #modal-wrapper .close-button { position: absolute; right: 13px; top: 13px; display: block; background: #3366CC; color: #fff; font-weight: bold; line-height: .75em; text-align: center; font-size: .75em; text-decoration: none; padding: 3px 3px 6px 6px; border-radius-bottom-left: 5px; border-bottom-left-radius: 10px; } #modal-content { background:#fff; border: 5px solid #3366CC; border-radius: 12px; font-family: Helvetica, Arial, sans-serif; font-size: 14px; overflow: hidden; padding: 24px; text-align: left; min-width: 280px; max-width: 444px; width: 280px; } #modal-content input.textbox, #modal-content select.dropdown { display: block; height: 28px; border: 1px solid #b7b7b7; color: #555; } #modal-content input.textbox { width: 253px; padding-left: 5px; line-height: 28px; vertical-align: middle; } #modal-content .select-wrapper { width: 258px; } #modal-content select { width: 100%; } #modal-content select option { padding-left: 5px; line-height: 28px; vertical-align: middle; } #modal-content label.label { cursor: pointer; padding-right: 10px; } #modal-content input.radio, #modal-content input.checkbox { margin-right: 5px; } #modal-content .buttons { margin-top: 20px; } #modal-content h1 { color: #3399ff; font-size: 24px; line-height: 26px; margin: 0 0 14px 0; } #modal-content p { color: #333333; line-height: 18px; margin: 0; padding: 0 0 12px 0; } #modal-content h3 { font-size:14px; color: #333333; padding:10px 0 0; margin:0; } #modal-content img { border: 0px none; } #modal-content .float-left { float: left; } #modal-content .left { width: 290px; } #modal-content .field { margin: 10px 0; } #modal-content button { cursor: pointer; } #modal-content .ltkmodal-subscribe { text-transform: uppercase; width: 100px; height: 34px; line-height: 34px; vertical-align: middle; text-align: center; font-weight: bold; background:#cc0000; color: #fff; border: 0px none; border-radius: 5px; -moz-border-radius: 5px; -webkit-border-radius: 5px; } #modal-content .ltkmodal-no-thanks { height: 36px; line-height: 36px; vertical-align: middle; text-align: center; font-weight: normal; background: #fff; color: #3366cc; border: 0px none; } #modal-content .ltkmodal-no-thanks:hover { text-decoration: underline; } #modal-content .right { position: relative; margin-left: 24px; } #ltkmodal-container { top:20% !important; left:50% !important; margin-left:-169px; } </style> <!--[if IE]> <style> #modal-wrapper .close-button { float:right; position:relative; top:-20px; left: 25px; display: block; background: #3366CC; color: #ffffff !important; font-weight: bold; line-height: .75em; text-align: center; font-family: Arial, Helvetica, sans-serif; font-size: .75em; text-decoration: none; padding: 6px; } #modal-content { background:#fff; font-size: 14px; overflow:hidden; padding: 24px; text-align: left; } </style> <![endif]--> <!--[if !IE]> --> <style> #modal-wrapper .close-button { position: absolute; right: 13px; top: 13px; display: block; background: #3366CC; color: #ffffff !important; font-weight: bold; line-height: .75em; text-align: center; font-family: Arial, Helvetica, sans-serif; font-size: .75em; text-decoration: none; padding: 3px 3px 6px 6px; border-radius-bottom-left: 5px; border-bottom-left-radius: 10px; } #modal-content { background:#fff; border: 5px solid #3366CC; border-radius: 12px; font-size: 14px; overflow: hidden; padding: 24px; text-align: left; } </style> <!-- <![endif]--> <!-- Form: END -->", confHTML: "<!-- Confirm: BEGIN --> <div id=\"modal-wrapper\"> <div id=\"modal-content\"> <a href=\"#\" class=\"ltkmodal-close close-button\">X</a> <h1>Thank You!</h1> <p>Thank you for signing up. Your welcome email will arrive shortly.</p> <p>Please <a href=\"#\" class=\"ltkmodal-close\" style=\"color:#3366cc;\">click here</a> to close this window.</p> </div> </div> <!-- Confirm: END -->", redirUrl: "", subCode: "ModalSignup", urlMode: "0", urlRules: ["addItems.do","getShoppingCart.do","checkout_custinfo.jsp"], name: "Modal Acquisition", testMode: false, autoload: true, overlayClose: false, uaSuppression: "" });
jQuery(document).ready(function(){_ltk.Modal.load();for(var i=0;i<_ltk.Modal.autoload.length;i++){_ltk.Modal.load(_ltk.Modal.autoload[i]);}});},100);

if (document.dispatchEvent)
{
    var customEvent = document.createEvent('Event');
    customEvent.initEvent('ltkAsyncListener', false, false);
    document.dispatchEvent(customEvent);
}
else if (document.fireEvent)
{
    document.documentElement.ltkAsyncProperty += 1;
}

