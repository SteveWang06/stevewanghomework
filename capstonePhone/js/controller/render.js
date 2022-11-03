
// hàm rút gọn get id
function getMyId(id) {
    return document.getElementById(id);
};
const URI = "https://634235dc20f1f9d7997ef83f.mockapi.io/api/phone";


// biến global
let phoneList = [];
let cartItem = []

// get data API
function getAllPhone() {
    // call API with method GET
    axios({
        method: "get",
        url: URI,

    }).then((res) => {
        // đổ dữ liệu ra biến GLOBAL
        phoneList = res.data
        //render ra giao diện
        renderProductAll(res.data);

    }).catch((err) => {
        console.log(err);
    });

};


// gọi hàm chạy khi vừa vô
window.onload = function () {
    // lấy giữ liệu khi vừa vô
    getAllPhone();
    //load lại dữ liệu giỏ hàng dưới local
    reloadData();
}



// luu xuong localstorage
function setLocalStorage(note, listData) {
    localStorage.setItem(note, JSON.stringify(listData));
}

// get data form localStorage
function getLocalStorage(note) {
    let result = JSON.parse(localStorage.getItem(note));
    if(!result) result = [];
    return result;
}

// hàm tạo thẻ HTML
function createHTML(image, name, price, screen, backCamera, frontCamera, desc, id) {
    return html = `
    <div class="item col-lg-3 mb-3">
        <div class="item__detail">
            

            <div class="item__top">
                <div class="item__img">
                    <img src="${image}" alt="phone" class="img-fluid">
                    <img src="#" alt="" class="img-fluid">
                </div>  
            </div>

            

            <div class="item__bottom">
                <p>${name}</p>
                <div class="item__price">
                    <span><b>${price.toLocaleString()}</b><b>$</b></span>
                </div>
            </div>
            <br />
            <div>
                <p>màng hình: ${screen}</p>
                <p>camera sau: ${backCamera}</p>
                <p>camera trước: ${frontCamera}</p>
                <p>miêu tả: ${desc}</p>
            </div>

            <div class="item__shop">
                <button onclick="addToCart(${id})">Add To Cart</button>
            </div>
            
        </div>

        
    </div>
    `
}

// render sản phẩm all 
function renderProductAll(arrPhone, id) {
    if (!arrPhone) arrPhone = phoneList;

    // tạo biến hứng kết quả để in ra giao diện
    let phoneHTML = "";

    // map san phẩm ra thẻ html
    arrPhone.map((sp) => {

        phoneHTML += createHTML(sp.image, sp.name, sp.price, sp.screen, sp.backCamera, sp.frontCamera, sp.desc, sp.id);
    });
    // render ra giao diện
    if (!id) id = 'allItem';
    getMyId(id).innerHTML = phoneHTML;
}



// render điện thoại hãng iphone

function renderTypePhone(type, id) {

    let iphoneHTML = '';

    let phone = phoneList.filter(sp => sp.type === type);


    phone.map((sp) => {
        iphoneHTML += createHTML(sp.image, sp.name, sp.price, sp.screen, sp.backCamera, sp.frontCamera, sp.desc, sp.id);
    })

    console.log(id);
    // render ra giao dien
    if (!id) id = 'allItem';
    getMyId(id).innerHTML = iphoneHTML;

}

// render trang san pham theo type

function renderType(type) {

    renderTypePhone(type, 'renderType');
}


// hàm tìm kiếm

function searchPhone() {

    // lấy giá trị input và mảng sản phẩm dưới local ra 
    let keyWord = (getMyId('keyWord').value).toLowerCase();

    let result = [];
    for (let i in phoneList) {
        let phoneType = phoneList[i].type.toLowerCase().trim();
        let phoneName = phoneList[i].name.toLowerCase().trim();
        if (phoneName.includes(keyWord) || phoneType.includes(keyWord)) {
            result.push(phoneList[i]);
        }
    }
    renderProductAll(result, 'renderType')
}

// tạo sản phẩm mới cho giỏ hàng có thêm thuộc tính là số lượng



// add to cart
function addToCart(id) {
    let item = phoneList.find(sp => sp.id === id);
    let cartShop = {product: item, quantity: 1}
    if(!cartItem){
        cartItem.push(cartShop)
        getMyId('quantity').innerHTML = cartItem.quantity;
        return;
    }else{
        for (let i = 0; i < cartItem.length; i++){
            if(cartItem[i].product.id === item.id){
                cartItem[i].quantity += 1;
                return;
            }
        }
        cartItem.push(cartShop);
               
    }
    let quantity = cartItem.reduce((total,item) => {
        return total += item.quantity;
    },0)
   getMyId('quantity').innerHTML = quantity
   setLocalStorage('cartLocal', cartItem);
    
}

// hàm render giỏ hàng
function renderCart() {
        
    let renderHTML = '';
    cartItem.map((item) => {
        renderHTML += `
        <div class="item-cart">
            <div class="cart-img">
                <img src="${item.product.image}" class="img-fluid">
            </div>
            <div class="countItem">
                <i onclick="reduceNum('${item.product.id}')" class="fa fa-angle-left"></i>
                <span class="amount">${item.quantity}</span>
                <i onclick="addQuantity('${item.product.id}')" class="fa fa-angle-right"></i>
            </div>
            <div class="cart-name">
                <span>${item.product.name}</span>
                <span class="price">$ ${(item.product.price*item.quantity).toLocaleString()}</span>
            </div>
            <i onclick="deletedCart('${item.product.id}')" class="fa fa-trash-alt remove-cart"></i>
        
        </div>
        `
    });

    // tính tổng tiền:
    let total = cartItem.reduce((totalAll, item, index) => {
        return totalAll += item.product.price * item.quantity;
    }, 0);
    getMyId('totalAllItem').innerHTML = `${total.toLocaleString()} $`;

    // in ra giao diện
    getMyId('cartHTML').innerHTML = renderHTML;
    getMyId('showCart').style.display = 'block'

}


// xóa sản phẩm khỏi giỏ hàng
function deletedCart(id) {
    for (let i = 0; i < cartItem.length; i++) {
        if (cartItem[i].product.id === id) {
            cartItem.splice(i, 1);
        }
    }
    
    // tính số lượng sản phẩm
    let tagSpan = cartItem.reduce((SL, item) => {
        return SL += item.quantity
    }, 0)

    //in số lượng ra giỏ hàng  
    getMyId('quantity').innerHTML = tagSpan;
    renderCart()
    setLocalStorage('cartLocal', cartItem);
}

//thêm số lượng vào giỏ hàng
function addQuantity(id) {
    let quantity = cartItem.find(sp => sp.product.id === id);

    // tăng số lượng trong giỏ hàng
    if(quantity){
        let count = quantity.quantity += 1;
    }

    // tính số lượng sản phẩm
    let tagSpan = cartItem.reduce((SL, item) => {
        return SL += item.quantity
    }, 0);
    //in số lượng ra giỏ hàng  
    getMyId('quantity').innerHTML = tagSpan;
    renderCart()
    setLocalStorage('cartLocal', cartItem);
}

// giảm số lượng sản phẩm giỏ hàng
function reduceNum(id) {
    let quantity = cartItem.find(sp => sp.product.id === id);

    let count = quantity.quantity -= 1;

    // tính số lượng sản phẩm
    let tagSpan = cartItem.reduce((SL, item) => {
        return SL += item.quantity
    }, 0)

    //in số lượng ra giỏ hàng  
    getMyId('quantity').innerHTML = tagSpan;
    renderCart()
    if (count <= 0) {
        for (let i = 0; i < cartItem.length; i++) {
            if (cartItem[i].product.id === id) {
                cartItem.splice(i, 1);

            }
        }
        renderCart()
    }
    // lưu xuống local
    setLocalStorage('cartLocal', cartItem);

   
}

// xóa toàn bộ giỏ hàng
function deleteAllCart() {
    cartItem = [];

    // tính số lượng sản phẩm
    let tagSpan = cartItem.reduce((SL, item) => {
        return SL += item.quantity
    }, 0)

    //in số lượng ra giỏ hàng  
    getMyId('quantity').innerHTML = tagSpan;
    setLocalStorage('cartLocal', cartItem);
    renderCart()
    closeCart('showCart')

}

// hoan tat thanh toan
function completedPay() {
    deleteAllCart()
    alert('Thanh Toán Thành Công')
}

// close cart
function closeCart(id) {
    if(!id) id = 'showCart';
    getMyId(id).style.display = 'none';
}

function reloadData() {
    cartItem = getLocalStorage('cartLocal');
    let quantity = cartItem.reduce((total,item) => {
        return total += item.quantity;
    },0)
   getMyId('quantity').innerHTML = quantity
}









